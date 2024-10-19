class Bank {
public:
    vector<long long>& balance;

    Bank(vector<long long>& balance) : balance(balance) {}
    bool possible(int account) {
        return (account <= 0 or account > balance.size());
    }
    bool transfer(int account1, int account2, long long money) {
        if (possible(account1) or possible(account2))
            return false;

        if (balance[account1 - 1] >= money) {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (possible(account))
            return false;

        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (possible(account))
            return false;

        if (balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};
