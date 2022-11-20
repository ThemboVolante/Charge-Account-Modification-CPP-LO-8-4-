// Charge Account Validation (CPP LO 8-1)
// J Poore, CIS 61

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
bool accountSecurity(int);

int main() {
  int userInput{0};
  int attempts{0};
  const int MAX_ATTEMPTS{3};
  
  // Program Header
  cout << "Welcome to Grüber Bank Systems" << endl;
  cout << "------------------------------" << endl;

  //Input Validation
  /* So, I deviated from the standard format. I decided since the theme was banking
     it would be appropriate to keep the array outside of the main function, so the
     account numbers would be protected. I then added input validation to make sure
     only 7 digit inputs were accepted, and rolling with the security theme, used a
     for loop to "protect" the system from brute force attacks. Happy Thanksgiving! */
  
  for (attempts = 0; attempts < MAX_ATTEMPTS; attempts++) 
  {
    if (userInput < 1000000 || userInput > 9999999 || !accountSecurity(userInput))
    {
      if (attempts > 0) 
      {
        cout << "User Input Invalid. You have " << MAX_ATTEMPTS - attempts << " attempts remaining." << endl;
      }
    cout << "Please enter your seven digit " << endl;
    cout << "account number: ";
    cin >> userInput;
    }
  }
    if(attempts == MAX_ATTEMPTS && !accountSecurity(userInput))
    {
      cout << "Maximum number of attempts exceeded. Disconnecting.";
    }
    else
    {
      cout << "Account Validated.";  
    }
}

// Function Definition
bool accountSecurity(int userInput)
  {
    const int ARRAY_SIZE = 18;
    int i{0};
    bool result=false;
    
    int userAccounts[18] = {5658845, 8080152, 1005231, 
                            4520125, 4562555, 6545231, 
                            7895122, 5552012, 3852085, 
                            8777541, 5050552, 7576651,
                            8451277, 7825877, 7881200, 
                            1302850, 1250255, 4581002};

    while (i < ARRAY_SIZE && !result)
      {
        if (userAccounts[i] == userInput)
        {
          result = true;
        }
        i++;
      }
  
    return result;
  }