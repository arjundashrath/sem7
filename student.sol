pragma solidity ^0.6.0;

contract Records{
    struct Student{
        int rollNumber;
        string name;
        string department;
        int percentage;
    }

    mapping(int => Student) public Students;

    function addRecord(int _roll, string memory _name, string memory _dept, int _percentage ) public{
        Students[_roll] = Student(_roll, _name, _dept, _percentage);
    }

    fallback() external payable{
            revert("Could not find student details");
    }

    function queryRecord(int _roll) public view returns(int , string memory, string memory, int){
        if(Students[_roll].rollNumber == 0){
            revert("No ID found");
        }
        return (Students[_roll].rollNumber, Students[_roll].name, Students[_roll].department, Students[_roll].percentage);
    }
}
