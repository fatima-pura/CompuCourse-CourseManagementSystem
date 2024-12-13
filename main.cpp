#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

// ----------------------------------------------------GLOBAL SCOPE / GOBAL VARIABLES --------------------------------------------------------------
char r7 = 220;

struct Student {
    string name;            
    string srCode;
    string college;
	string program;
	string IT_track;         
    string courses[8];      
    string yearLevel;       
    int courseCount = 0;
	string semester; 
};

Student students[5000];      
int studentCount = 0; 
int semesterChoice;      

// ---------------------------------------------------------FUNCTION PROTOTYPES -----------------------------------------------------------------
void upperDesign();
void displayMenu();
void createAccount();
void ShowEnrolledCourses();
void EnrollinCourses();
void deleteCourse();
;
// --------------------------------------------------------------MAIN MENU----------------------------------------------------------------------
int main(){
	char choice;
	 
    do {
	    system("CLS");
	    upperDesign();
	    
		displayMenu();
		cin >> choice;
	
		switch(choice) {
			case '1':
				system("CLS");
				createAccount();
				break;
			case '2':
				system("CLS");
				ShowEnrolledCourses();
				break;
			case '3':
				system("CLS");
				EnrollinCourses();
				break;
			case '4':
				system("CLS");
				deleteCourse();
				break;
			case '5':
                cout << "\nExiting the program. Goodbye... Thank You :)\n";
                break;
            default:
                cout << "\nInvalid choice. Please select a valid option (1-5).\n";
                break;
        }
		
	} while(choice != '5');

	return 0;
}

//-----------------------------------------------------------------UPPER DESIGN----------------------------------------------------------------------
void upperDesign() {
	cout << endl;
	for (int i = 0; i < 120; i++) {
		cout << r7;
	}
	
	cout << endl;
	cout << "\n\t\t\t\t\t       Batangas State University" << endl;
	cout << "\t\t\t\t          The National Engineering University" << endl;
	
	cout << endl;
	cout << "\t\t\t\t\t\t    compuCourse" << endl;
	cout << endl;
	cout << "\t\t\t\t\t      by Fatima Pura | CS - 1104";
	cout << endl;
	
     for (int i = 0; i < 120; i++) {
		cout << r7;
	}
	cout << endl;	
}

void displayMenu() {
	cout << "\n\n\t\t\t\t\t\t   -- MAIN MENU --";
	cout << endl;
	cout << "\n\t\t\t\t        Press 1:   CREATE | Create an Account";
	cout << "\n\t\t\t\t        Press 2:   READ   | Show Enrolled Courses";
	cout << "\n\t\t\t\t        Press 3:   UPDATE | Enroll in a Course";
	cout << "\n\t\t\t\t        Press 4:   DELETE | Unenroll from a Course";
	cout << "\n\t\t\t\t        Press 5:   EXIT   | Exit the Program";
	cout << endl;
	cout << "\n\t\t\t\t        Select Your Option (1-5): ";
	
}


//--------------------------------------------------------------------CREATE-----------------------------------------------------------------------------------
void createAccount() {
    int programChoice, trackChoice, yearOption;
    bool validCollege = false;

    if (studentCount >= 5000) {
        upperDesign();
        cout << "\n\n\t\t\t\t\t\t  --CREATE ACCOUNT--" << endl;
        cout << "\nCannot create more accounts. Student limit reached.\n";
        cout << "\nPress Enter to return to the main menu.";
        cin.ignore();
        cin.get();
        return;
    }

    upperDesign();
    cout << "\n\n\t\t\t\t\t\t  --CREATE ACCOUNT--" << endl;
    cout << endl;

    cin.ignore();  
    
    cout << "Enter your name (Ex. Fatima A. Pura): ";
    getline(cin, students[studentCount].name);

    cout << "\nEnter your SR-CODE: ";
    getline(cin, students[studentCount].srCode);
    
    
    while (!validCollege) {
        cout << "\nEnter your college: ";
        cout << "\nPress 1:  College of Engineering, Architecture and Fine Arts [CEAFA]  | Not Available";
        cout << "\nPress 2:  College of Industrial Technology [CIT]                      | Not Available";
        cout << "\nPress 3:  College of Informatics and Computing Sciences [CICS]        | Available";
        cout << "\nSelect Your Option (1-3): ";
        getline(cin, students[studentCount].college);
        
        if (students[studentCount].college == "1" || students[studentCount].college == "2") {
            cout << "College Not Available... Exclusively for CICS students only.\n";
        } else if (students[studentCount].college == "3") {
            students[studentCount].college = "College of Informatics and Computing Sciences [CICS]";
            validCollege = true;  
        } else {
            cout << "Invalid input! Please select a valid college (1-3).\n";
            getline(cin, students[studentCount].college);
        }
    }

    cout << "\nEnter your program: ";
    cout << "\nPress 1:  BS Computer Science";
    cout << "\nPress 2:  BS Information Technology";
    cout << "\nSelect Your Option (1-2): ";
    cin >> programChoice;
    cin.ignore();  

    if (programChoice == 1) {
        students[studentCount].program = "BS Computer Science";
    } else if (programChoice == 2) {
        students[studentCount].program = "BS Information Technology";
        
        cout << "\nEnter Track: ";
        cout << "\nPress 1:  Network Technology Track" << endl;
        cout << "Press 2:  Business Analytics Track" << endl;
        cout << "Press 3:  Service Management Track" << endl;
        cout << "Select Your Option (1-3): ";
        cin >> trackChoice;
        cin.ignore(); 
        
        if (trackChoice == 1) {
            students[studentCount].IT_track = " - Network Technology Track";
        } else if (trackChoice == 2) {
            students[studentCount].IT_track = " - Business Analytics Track";
        } else if (trackChoice == 3) {
            students[studentCount].IT_track = " - Service Management Track";
        }
    } else {
        cout << "Invalid input! Please select a valid program (1-3).\n";
        cin >> trackChoice;
    }

    cout << "\nEnter your year level:" << endl;
    cout << "Press 1:  1st Year | Available\n";
    cout << "Press 2:  2nd Year | Not Yet Available\n";
    cout << "Press 3:  3rd Year | Not Yet Available\n";
    cout << "Press 4:  4th Year | Not Yet Available\n";
    cout << "Select Your Option (1-4): ";
    cin >> yearOption;
    cin.ignore();  

    while (true) {
        if (yearOption == 1) {
            students[studentCount].yearLevel = "1st Year";
            break;
        } else if (yearOption >= 2 && yearOption <= 4) {
            cout << "Selected year level is not yet available.\n";
            cout << "Please try again." << endl;
            cout << "Select a valid year level (1-4): ";
            cin >> yearOption;
            cin.ignore();  
        } else {
            cout << "Invalid input! Please select a valid year level (1-4): ";
            cin >> yearOption;
            cin.ignore();  
        }
    }
	
    cout << "\nEnter the semester: \n";
    cout << "Press 1:  1st Semester\n";
    cout << "Press 2:  2nd Semester\n";
    cout << "Press 3:  Summer\n";
    cout << "Select from (1-3): ";
    cin >> semesterChoice;
    
    while(true) {
    	if((students[studentCount].program == "BS Computer Science" || students[studentCount].program == "BS Information Technology" ) && 
			semesterChoice == 1) {
	    		students[studentCount].semester = "1st Semester";
	    		break;
		} else if((students[studentCount].program == "BS Computer Science" || students[studentCount].program == "BS Information Technology") &&
			 semesterChoice == 2) {
				students[studentCount].semester = "2nd Semester";
				break;
		}else if(students[studentCount].program == "BS Computer Science"  && semesterChoice == 3) {
				students[studentCount].semester = "Summer";
				break;
		}else if(students[studentCount].program == "BS Information Technology"  && semesterChoice == 3) {
				cout << "No summer classes...";
				cout << "\nSelect from (1-3): ";
    			cin >> semesterChoice;		
		} else {
				cout << "\nInvalid Input. Select from (1-3):";
    			cin >> semesterChoice;
		}
    	
	}
    
    cout << "\nAccount created successfully...\n";
    studentCount++;  

    cout << "\nPress Enter to return to the main menu.";
    cin.ignore();
    cin.get();
}

// ------------------------------------------------------------------READ-----------------------------------------------------------------------------------
void ShowEnrolledCourses() {
    if (studentCount == 0) {
        upperDesign();
        cout << "\n\n\t\t\t\t\t      --SHOW ENROLLED COURSES--" << endl;
        cout << "\nNo accounts registered yet. Please proceed to the main menu and select option 1." << endl;
        cout << "\nPress Enter to return to the main menu.";
        cin.ignore();
        cin.get();
        return;
    }

    upperDesign();
    cout << "\n\n\t\t\t\t\t      --SHOW ENROLLED COURSES--" << endl;
    cout << endl;

    for (int i = 0; i < studentCount; i++) {
        cout << "\nName: " << students[i].name;
        cout << "\nSR-CODE: " << students[i].srCode;
        cout << "\nCollege: " << students[i].college;
        cout << "\nProgram: " << students[i].program;

        if (!students[i].IT_track.empty()) {
            cout << students[i].IT_track;
        }

        cout << "\nYear Level: " << students[i].yearLevel;
        cout << "\nSemester: " << students[i].semester;
        cout << endl;
        cout << "\nEnrolled Courses (" << students[i].courseCount << " / 8): ";

        if (students[i].courseCount != 0) {
            for (int j = 0; j < students[i].courseCount; j++) {
                cout << "\nCourse Code: " << students[i].courses[j];
                cout << "\nSection: To be Announced";
                cout << "\nProfessor: To be Announced";
                cout << endl;
            }
        } else {
            cout << "\nNo courses enrolled yet.";
        }

        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    }

    cout << "\nPress Enter to return to the main menu.";
    cin.ignore();
    cin.get();
}

//-----------------------------------------------------------------UPDATE-----------------------------------------------------------------------------------
void EnrollinCourses() {
    string searchSRCODE, courseCode;
    bool found = false;

    upperDesign();
    cout << "\n\n\t\t\t\t\t        --ENROLL IN A COURSE--" << endl;\
    
    cout << "\nEnter your SR-CODE: ";
    cin >> searchSRCODE;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].srCode == searchSRCODE) {
            found = true;

            if (students[i].courseCount >= 8) {
                cout << "Cannot enroll in more courses. Limit reached.\n";
                break;
            }

            if (semesterChoice < 1 || semesterChoice > 3) {
                cout << "\nInvalid semester choice. Please try again.\n";
                continue;
            }

            cin.ignore(); 

            if (students[i].program == "BS Computer Science") {
                if (semesterChoice == 1) {
                    cout << "\nCourses Offered in BS Computer Science: 1st Semester\n";
                    cout << endl;
                    cout << "COURSE CODE | COURSE NAME                                        | UNITS\n";
                    cout << "---------------------------------------------------------------------------\n";
                    cout << "IT 111      | Introduction to Computing                          | 3 units\n";
                    cout << "CS 111      | Computer Programming                               | 3 units\n";
                    cout << "Fili 101    | Kontekstwalisadong Komunikasyon sa Filipino        | 3 units\n";
                    cout << "GEd 101     | Understanding the Self                             | 3 units\n";
                    cout << "GEd 102     | Mathematics in the Modern World                    | 3 units\n";
                    cout << "Math 111    | Linear Algebra                                     | 3 units\n";
                    cout << "PE 101      | Physical Fitness, Gymnastics and Aerobics          | 2 units\n";
                    cout << "NSTP 111    | National Service Training Program 1                | 3 units\n";
                } else if (semesterChoice == 2) {
                    cout << "\nCourses Offered in BS Computer Science: 2nd Semester\n";
                    cout << endl;
                    cout << "COURSE CODE | COURSE NAME                                        | UNITS\n";
                    cout << "---------------------------------------------------------------------------\n";
                    cout << "CS 121      | Advanced Computer Programming                      | 3 units\n";
                    cout << "Fili 102    | Filipino sa Iba't Ibang Disiplina                  | 3 units\n";
                    cout << "GEd 105     | Readings in Philippine History                     | 3 units\n";
                    cout << "GEd 108     | Art Appreciation                                   | 3 units\n";
                    cout << "Math 401    | Differential Calculus                              | 3 units\n";
                    cout << "Math 407    | Number Theory                                      | 3 units\n";
                    cout << "PE 102      | Rhythmic Activities                                | 2 units\n";
                    cout << "NSTP 121    | National Service Training Program 2                | 3 units\n";
                } else if (semesterChoice == 3) {
                    cout << "\nCourses Offered in BS Computer Science: Summer\n";
                    cout << endl;
                    cout << "COURSE CODE | COURSE NAME                                        | UNITS\n";
                    cout << "---------------------------------------------------------------------------\n";
                    cout << "CS 131      | Data Structures and Algorithms                     | 3 units\n";
                    cout << "Math 402    | Integral Calculus                                  | 3 units\n";
                    cout << "Litr 102    | ASEAN Literature                                   | 3 units\n";
                }

                cout << "\nEnter COURSE CODE to enroll (or type '#' to exit): ";
                
				while (students[i].courseCount < 8) {
                    getline(cin, courseCode);
		                    for (int j = 0; j < courseCode.length(); j++) {
		                	courseCode[j] = toupper(courseCode[j]);
		            		}

                    if (courseCode == "#") {
                        cout << "\nExiting course enrollment.\n";
                        break;
                    }

                    students[i].courses[students[i].courseCount] = courseCode;
                    students[i].courseCount++;

                    cout << "Course added successfully! You are now enrolled in "
                         << students[i].courseCount << "/8 courses.\n";

                    if (students[i].courseCount < 8) {
                        cout << "\nEnter another COURSE CODE to enroll (or type '#' to exit): ";
                    }
                }

                if (students[i].courseCount >= 8) {
                    cout << "You have reached the maximum course limit.\n";
                }
                break;
            } else if (students[i].program == "BS Information Technology") {
			    if (semesterChoice == 1) {
			        cout << "\nCourses Offered in BS Information Technology: 1st Semester\n";
			        cout << endl;
			        cout << "COURSE CODE | COURSE NAME                                        | UNITS\n";
			        cout << "---------------------------------------------------------------------------\n";
			        cout << "IT 111      | Introduction to Computing                          | 3 units\n";
			        cout << "GEd 102     | Mathematics in the Modern World                    | 3 units\n";
			        cout << "GEd 108     | Art Appreciation                                   | 3 units\n";
			        cout << "Fili 101    | Kontekstwalisadong Komunikasyon sa Filipino        | 3 units\n";
			        cout << "PE 101      | Physical Fitness, Gymnastics and Aerobics          | 2 units\n";
			        cout << "NSTP 111    | National Service Training Program 1                | 3 units\n";
			        cout << "GEd 103     | The Life and Works of Rizal                        | 3 units\n";
			        cout << "GEd 104     | The Contemporary World                             | 3 units\n";
			
			    } else if (semesterChoice == 2) {
			        cout << "\nCourses Offered in BS Information Technology: 2nd Semester\n";
			        cout << endl;
			        cout << "COURSE CODE | COURSE NAME                                        | UNITS\n";
			        cout << "---------------------------------------------------------------------------\n";
			        cout << "CS 111      | Computer Programming                               | 3 units\n";
			        cout << "CS 131      | Data Structures and Algorithms                     | 3 units\n";
			        cout << "Math 111    | Linear Algebra                                     | 3 units\n";
			        cout << "Fili 102    | Filipino sa Iba't Ibang Disiplina                  | 3 units\n";
			        cout << "GEd 105     | Readings in Philippine History                     | 3 units\n";
			        cout << "GEd 109     | Science, Technology and Society                    | 3 units\n";
			        cout << "PE 102      | Rhythmic Activities                                | 2 units\n";
			        cout << "NSTP 121    | National Service Training Program 2                | 3 units\n";
			    }
				
				cout << "\nEnter COURSE CODE to enroll (or type '#' to exit): "; 
                while (students[i].courseCount < 8) {
                    getline(cin, courseCode);
	                    for (int j = 0; j < courseCode.length(); j++) {
		                	courseCode[j] = toupper(courseCode[j]);
		            	}


                    if (courseCode == "#") {
                        cout << "\nExiting course enrollment.\n";
                        break;
                    }

                    students[i].courses[students[i].courseCount] = courseCode;
                    students[i].courseCount++;

                    cout << "Course added successfully! You are now enrolled in "
                         << students[i].courseCount << "/8 courses.\n";

                    if (students[i].courseCount < 8) {
                        cout << "\nEnter another COURSE CODE to enroll (or type '#' to exit): ";
                    }
                }

                if (students[i].courseCount >= 8) {
                    cout << "\n\nYou have reached the maximum course limit.\n";
                }
                break;	
        	} 
    	}
	}	

    if (!found) {
        cout << "\nStudent not found.\n";
    }

    cout << "\nPress Enter to return to the main menu.";
    cin.ignore();
    cin.get();

}

//--------------------------------------------------------------DELETE----------------------------------------------------------------------------------------
void deleteCourse() {
    string searcSRCODE;
    int courseIndex;
    
    upperDesign();
    cout << "\n\n\t\t\t\t\t        --UNENROLL FROM A COURSE--" << endl;
    
	cout << "Enter your SR-CODE: ";
    cin.ignore();
    getline(cin, searcSRCODE);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].srCode == searcSRCODE) {
            if (students[i].courseCount == 0) {
                cout << "No courses to unenroll from.\n";
                return;
            }

            cout << "\nEnrolled Courses (" << students[i].courseCount << "/8):\n";
            for (int j = 0; j < students[i].courseCount; j++) {
                cout << "Press " << j + 1 << " : " << students[i].courses[j] << endl;
            }

            cout << "\n\nEnter the number of the course to unenroll: ";
            cin >> courseIndex;

            if (courseIndex < 1 || courseIndex > students[i].courseCount) {
                cout << "Invalid Input.\n";
                return;
            }

            for (int j = courseIndex - 1; j < students[i].courseCount - 1; j++) {
                students[i].courses[j] = students[i].courses[j + 1];
            }
            students[i].courseCount--;
            cout << "Course unenrolled successfully. You are now enrolled in " << students[i].courseCount << "/8 courses.\n";
            return;
        }
    }

    cout << "Student not found. Please check the name entered.\n";
}

