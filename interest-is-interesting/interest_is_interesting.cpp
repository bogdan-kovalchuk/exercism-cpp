// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance)
{
    double interest_rate = 0;

    if (balance < 0)
    {
        interest_rate = 3.213;
    }
    else if (balance >= 0 && balance < 1000)
    {
        interest_rate = 0.5;
    }
    else if (balance >= 1000 && balance < 5000)
    {
        interest_rate = 1.621;
    }
    else
    {
        interest_rate = 2.475;
    }

    return interest_rate;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance)
{
    return interest_rate(balance) * balance / 100.0;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance)
{
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance)
{
    int years = 0;
    while (balance < target_balance)
    {
        balance = annual_balance_update(balance);
        years++;
    }
    return years;
}
