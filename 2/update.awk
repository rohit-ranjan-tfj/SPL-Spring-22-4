#!/usr/bin/gawk -f

# utility fucntion to round float to nearest integer
function round(n)
{
    int_part = int(n)
    decimal = n-int(n)
    if(decimal>=0.5){int_part+=1}
    return int_part
}

BEGIN {

    # defining separaters
    FS=":"
    OFS=":"

    # new_file stores name of file to be updated
    new_file = ""
    final_file = "account-out.txt"

    # title of the previous action in the passbook
    prev_title =""

    # year of previous record
    prev_year = ""

    # balance of previous record
    prev_bal=0

    # days will be 365/366 depending on year
    days = 0

    # interest accrued in present year
    interest_till_date = 0

    # current balance
    bal = 0

    # flag for type of year
    flag=0

    # flag for whether transactions are found
    trans_flag=0;

    # array to contain days in months
    split("31,29,31,30,31,30,31,31,30,31,30,31",leap_year,",")
    split("31,28,31,30,31,30,31,31,30,31,30,31",non_leap_year,",")

    # array to contain names of months
    split("January,February,March,April,May,June,July,August,September,October,November,December",months,",")
}
{
    # if interest was just calculated reset the accrued interest
    if(prev_title=="INTEREST" || prev_title=="INTEREST\r" ||  $5=="INTEREST"){
        interest_till_date=0;
    }

    # set flags for type of year
    split($1,curr_split_date,"-")
    curr_year = curr_split_date[3]
    if(((int(prev_split_date[3])-2000) %4)==0){
        days=366
        flag=1
    }
    else
    {
        days_int=365
        flag_int=0
    } 

    # code block for addition of interest on last day of year
    if(prev_year!="" && prev_year !=curr_year && prev_title!="INTEREST" && prev_title!="INTEREST\r" && $5!="INTEREST"){
        if(prev_year!=""){
            if(12 == prev_split_date[2] ){
                time_spent_last = 31 - prev_split_date[1]
            }
            else{
                if(flag==0){
                    time_spent_last = non_leap_year[int(prev_split_date[2])] - int(prev_split_date[1])
                    time_spent_last += int(31)
                    for(i =int(prev_split_date[2])+1;i<int(12);i++)
                    {
                        time_spent_last+=int(non_leap_year[i])
                    }
                }
                else{
                    time_spent_last = leap_year[int(prev_split_date[2])] - int(prev_split_date[1])
                    time_spent_last += int(31)
                    for(i =int(prev_split_date[2])+1;i<int(12);i++)
                    {
                        time_spent_last+=int(leap_year[i])
                    }
                }
                
            }
        interest_till_date = interest_till_date + bal*(time_spent_last/days_int)*0.05
        bal = bal+round(interest_till_date) 
        new_file = new_file "" ("31-12-" prev_split_date[3] ":" round(interest_till_date) "::" bal ":INTEREST\n") 
        }
        prev_split_date[1] = "01"
        prev_split_date[2] = "01"
        prev_split_date[3] = int(curr_split_date[3]) + 1
        interest_till_date=0
    }

    # set flags for normal interest accruing
    if(((int(curr_split_date[3])-2000) %4)==0){
        days=366
        flag=1
    }
    else
    {
        days=365
        flag=0
    }   

    # codeblock to update balances
    if($4!="") {
        bal = $4
    }
    else { 
        trans_flag+=1
        if(trans_flag==1)
        {
            print("+++ New transactions found")
            print("Last Balance = " bal)
        }
        change = 0 
        if($2!=""){ change += int($2)}
        if($3!=""){ change += -1*int($3)}
        bal +=change
        $4 = bal
        printf("%25s",("Balance = "bal))
        printf("%25s",(months[int(curr_split_date[2])] " " curr_split_date[1] ", "  curr_split_date[3]))
        if(change<0){
            printf("%40s\n",("Debit of " (int($2)+int($3)) " for " $5) )
        }
        else{
            printf("%40s\n",("Credit of " (int($2)+int($3)) " for " $5) )
        }
        
    }

    # codeblock to calculate interests at present day
    if(prev_year!=""){
        if(curr_split_date[2] == prev_split_date[2] ){
            time_spent = curr_split_date[1] - prev_split_date[1]
        }
        else{
            if(flag==0){
                time_spent = non_leap_year[int(prev_split_date[2])] - int(prev_split_date[1])
                time_spent += int(curr_split_date[1])
                for(i =int(prev_split_date[2])+1;i<int(curr_split_date[2]);i++)
                {
                    time_spent+=int(non_leap_year[i])
                }
            }
            else{
                time_spent = leap_year[int(prev_split_date[2])] - int(prev_split_date[1])
                time_spent += int(curr_split_date[1])
                for(i =int(prev_split_date[2])+1;i<int(curr_split_date[2]);i++)
                {
                    time_spent+=int(leap_year[i])
                }
            }
            
        }
        if(prev_title!="INTEREST" && prev_title!="INTEREST\r" && $5!="INTEREST"){
            interest_till_date += prev_bal*(time_spent/days)*0.05
        }
    }
    new_file = new_file "" $0
    prev_year = curr_year
    prev_split_date[1] = curr_split_date[1]
    prev_split_date[2] = curr_split_date[2]
    prev_split_date[3] = curr_split_date[3]
    prev_bal = bal
    prev_title = $5
    
}
END	{
    if(trans_flag<=0){
        print("+++ No new transactions found")
    }
    printf("%s\n",("+++ Interest of this year up to the last transaction = " round(interest_till_date)))
    print(new_file) > final_file
}
