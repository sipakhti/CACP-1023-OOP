#include <iostream>
#include <string.h>

using namespace std;



class Employee{
    private:
    /**
     * @brief A simple date construct to store the date of birth
     * 
     */
    struct Date
    {
        int day;
        int month;
        int year;
 
        /**
         * @brief overload stream operator to print the date
         * 
         * @param out output stream
         * @param date object of the date
         * @return ostream& output stream
         */
        friend ostream& operator <<(ostream& out, const Date& date){
            out << date.day << "-" << date.month << "-" << date.year;
            return out;
        }
        
    };
    
        const int id;
        char* name;
        Date DOB;
        char* gender;
        char* contactNumber;
        double salary;
        char* shift;
        inline static int empCount;

        // method to copy a char* to another char*
        /**
         * @brief deep copies a char array to another char array.
         * The new char array is allocated dynamically and the old one is freed.
         * 
         * @param target char array to be copied to
         * @param source char array to be copied from
         * @return char* copied char array
         */
        char* copyStr(char* target, char* source){
            if (target != nullptr)
                delete[] target;
            int size = strlen(source);
            target = new char[size + 1]; // +1 for null terminator
            for (size_t i = 0; i < size; i++)
                target[i] = source[i];
            target[size] = '\0';       
            return target;     

        }

    public:
        // default constructor
        Employee() : id(0){
            name = nullptr;
            gender = nullptr;
            contactNumber = nullptr;
            salary = 0.0;
            shift = nullptr;
        }
        // constructor
        /**
         * @brief Construct a new Employee object
         * 
         * @param _id unique id of the employee
         * @param _name full name of the employee
         * @param _DOB dd-mm-yyyy
         * @param _gender its obvious
         * @param _contactNumber 0xxx-xxxxxxx
         * @param _salary better not be less than zero 
         * @param _shift employee shift
         */
        Employee(int _id,char* _name, char* _DOB, char* _gender, char* _contactNumber, double _salary, char* _shift) : id(_id) {
            // set all pointers to nullptr
            name = nullptr;
            gender = nullptr;
            contactNumber = nullptr;
            shift = nullptr;
            // called every setter
            setName(_name); 
            setDOB(_DOB);
            setGender(_gender);
            setContactNumber(_contactNumber);
            setSalary(_salary);
            setShift(_shift);
            cout << "Constructor Called!" << endl;
            Employee::incrementCount();
        }

        // copy constructor
        Employee(const Employee& emp) : id(emp.id) {
            setName(emp.name);
            DOB = emp.DOB;
            setGender(emp.gender);
            setContactNumber(emp.contactNumber);
            salary = emp.salary;
            setShift(emp.shift);
            cout << "COPY CONSTRUCTOR" << endl;
            Employee::incrementCount();
        }

        //Employee class Destructor
        ~Employee(){
            delete[] name;
            delete[] gender;
            delete[] contactNumber;
            delete[] shift;
            cout << "Destructor Called!" << endl;
            Employee::decrementCount();
        }

        // setter for name attribute
        /**
         * @brief Set the Name of employee
         * 
         * @param str name of the employee
         */
        void setName(char* str){
            name = copyStr(name, str);
        }

        // setter for DOB attribute
        /**
         * @brief set the date of birth of the employee
         * 
         * @param str dd-mm-yyyy make sure its correct
         */
        void setDOB(char* str){
            int day, month, year;
            sscanf(str, "%d-%d-%d", &day, &month, &year);
            DOB.day = day > 0 && day < 32 ? day : 0;
            DOB.month = month > 0 && month < 13 ? month : 0;
            DOB.year = year > 1900 && year < 2020 ? year : 0;
        }

        // setter for gender attribute
        /**
         * @brief Set the Gender of the employee
         * 
         * @param str gender of the employee
         */
        void setGender(char* str){
            gender = copyStr(gender, str);
        }

        // setter for contactNumber attribute
        /**
         * @brief Set the Contact Number of the employee
         * 
         * @param str 
         */
        void setContactNumber(char* str){
            contactNumber = copyStr(contactNumber, str);
        }

        // setter for salary attribute
        /**
         * @brief Set the Salary of the employee
         * 
         * @param _salary employee salary
         */
        void setSalary(double _salary){
            salary = _salary > 0 ? _salary : 0;
        }

        // setter for shift attribute
        /**
         * @brief Set the Shift of the employee
         * 
         * @param str employee shift
         */
        void setShift(char* str){
            shift = copyStr(shift, str);
        }

        // getter for name attribute
        /**
         * @brief Get the Name of the employee
         * 
         * @return char* name of the employee
         */
        char* getName(){
            char* temp = nullptr;
            return copyStr(temp, name);
        }

        // getter for DOB attribute
        /**
         * @brief Get the Date of Birth of the employee
         * 
         * @return Date date of birth of the employee
         */
        Date getDOB(){
            return DOB;
        }

        // getter for gender attribute
        /**
         * @brief Get the Gender of the employee
         * 
         * @return char* gender of the employee
         */
        char* getGender(){
            char* temp = nullptr;
            return copyStr(temp, gender);
 
        }

        // getter for contactNumber attribute
        /**
         * @brief Get the Contact Number of the employee
         * 
         * @return char* employee contact number
         */
        char* getContactNumber(){
            char* temp = nullptr;
            return copyStr(temp, contactNumber);
        }

        // getter for salary attribute
        /**
         * @brief Get the Salary of the employee
         * 
         * @return double salary of the employee
         */
        double getSalary(){
            return salary;
        }

        // getter for shift attribute
        /**
         * @brief Get the Shift of the employee
         * 
         * @return char* shift of the employee
         */
        char* getShift(){
            char* temp = nullptr;
            return copyStr(temp, shift);
        }

        // getter for id attribute
        /**
         * @brief Get the Id of the employee
         * 
         * @return int id of the employee
         */
        int getId(){
            return id;
        }

        // static method to get the number of employees
        /**
         * @brief Get the total number of the employees
         * 
         * @return int number of employees
         */
        static int getCount(){
            return empCount;
        }

        // static method to increment the number of employees
        /**
         * @brief Increment the number of employees
         * 
         */
        static void incrementCount(){
            empCount++;
        }

        // static method to decrement the number of employees
        /**
         * @brief Decrement the number of employees
         * 
         */
        static void decrementCount(){
            empCount--;
        }

        // static method to reset the number of employees
        /**
         * @brief  set the number of employees to zero
         * 
         */
        static void resetCount(){
            empCount = 0;
        }

};

// function to print the employee details
void printEmployee(Employee& employee){
    cout << "-----------------Employee Details--------------------" << endl;
    cout << "Employee ID: " << employee.getId() << endl;
    cout << "Name: " << employee.getName() << endl;
    cout << "Date of Birth: " << employee.getDOB() << endl;
    cout << "Contact Number: " << employee.getContactNumber() << endl;
    cout << "Salary: " << employee.getSalary() << endl;
    cout << "Shift: " << employee.getShift() << endl;
    cout << "Total Number of Employees: " << Employee::getCount() << endl;
    cout << "-----------------------------------------------------" << endl;

}
 // overloaded function to print the employee details
void printEmployee(const Employee& employee){
    printEmployee(const_cast<Employee&>(employee));
}

int main(){
    Employee::resetCount();
    char name[10] = "john";
    char DOB[15] = "01-01-2000";
    char gender[10] = "male";
    char phone[15] = "0334-0866209";
    char shift[10] = "morning";
    double salary = 80000;
    const Employee employeeConst(1, name, DOB,gender,phone,salary,shift);
    cin >> name;
    cin >> DOB;
    cin >> gender;
    cin >> phone;
    cin >> shift;
    salary = 90000;
    Employee employeeNonConst(2, name, DOB,gender,phone,salary,shift);

    printEmployee(employeeConst);
    printEmployee(employeeNonConst);

    return 0;
}