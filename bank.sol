pragma solidity ^0.4.25;

contract bankContract{

    int balance;

    constructor()public{
        balance = 0;
    }

    function Deposit(int val) public{
        balance = balance + val;
    }

    function Withdraw(int val) public{
        if(balance < val){
            revert("Insufficient Balance");
        }
        balance = balance - val;

    }

    function checkBalance() public view returns(int){
        return balance;
    }

}
