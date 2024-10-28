#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Function to simulate installing PostgreSQL
void Install_Postgresql() {
    cout << "\nInstalling IntegreDB PostGres Server..." << endl;
    
     system("sudo apt update");
     system("sudo apt install -y postgresql postgresql-contrib");
    cout << "\nInstallation Complete Successfully." << endl;
}

// Function to simulate installing PostGIS
void Postgis() {
    cout << "\nInstalling IntegreDB PostGis extension..." << endl;
    
     system("sudo apt update");
     system("sudo apt install -y postgresql postgresql-contrib postgis");
    cout << "\nInstallation Complete Successfully." << endl;
}

// Function to install both PostgreSQL and PostGIS
void PostGres_PostGis() {
    Install_Postgresql();
    Postgis();
}

int main() {
    //clrscr();
    system("clear");
    cout << "\n\n\n";
    // Displaying the content of "image.txt" file (if exists)
    
    system("cat image.txt");

    int choice = 0;
    int count = 0;
    const int maxAttempts = 5;

    while (count < maxAttempts) {
        cout << "\n\tYou are about to install IntegreDB Server,\n"
             << "\tBelow is the licensing, Terms, and conditions for the same.\n"
             << "\tYou can then choose from the options below:\n" << endl;

        cout << "1) IntegreDB Postgres Server" << endl;
        cout << "2) Server Along with extension PostGis" << endl;
        cout << "3) PostGis" << endl;
        cout << "\nEnter Choice: ";
        cin >> choice;

        // Handling the choice using a switch statement
        switch (choice) {
            case 1:
                Install_Postgresql();
                break;
            case 2:
                PostGres_PostGis();
                break;
            case 3:
                Postgis();
                break;
            default:
                if (count < maxAttempts) {
                    cout << "\nInvalid argument. Try again." << endl;
                    count++;
                    continue;
		} else {
                    cout << "\nMaximum attempts reached. Exiting..." << endl;
                     count++;
                    break;
                }
        }
    }

    // Continue if the user made a valid selection
    if (count == maxAttempts) {
	return 0;
    }
        cout << "\nEnabling and starting PostgreSQL service..." << endl;
        
         system("sudo systemctl enable postgresql");
         system("sudo systemctl start postgresql");

        cout << "\nConfiguring PostgreSQL for local access" << endl;
        cout << "\nPlease Enter Password for Security change for 'postgres' user." << endl;

        string password;
        cout << "Password: ";
        cin >> password;

        // To execute the password change, uncomment the line below.
        
         string command = "sudo -u postgres psql -c \"ALTER USER postgres PASSWORD '" + password + "'\"";
         system(command.c_str());

        cout << "\nPostgreSQL has been configured with a default password for the 'postgres' user." << endl;
        cout << "\nThanks for using IntegreDB Server application :)" << endl;
    

    return 0;
}

