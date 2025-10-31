#include <bits/stdc++.h>
using namespace std;
map<int, vector<string>> r;
class Member
{
protected:
    string name;
    int age;
    double weight, height;

public:
    Member(){};
    Member(string n, int a, double w, double h)
    {
        name = n;
        age = a;
        weight = w;
        height = h;
    }
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " Years" << endl;
        cout << "Weight: " << weight << " Kg" << endl;
        cout << "Height: " << height << " meters" << endl;
    }
};
class RegularMember : public Member
{
private:
    int membershipId;

public:
    RegularMember(){};
    RegularMember(string n, int a, double w, double h, int id) : Member(n, a, w, h)
    {
        r[id] = {n, to_string(a), to_string(w), to_string(h)};
        membershipId = id;
    }
    virtual void ifexist(int id)
    {
        cout << "Name " << r[id][0] << endl;
        cout << "Age " << r[id][1] << " Years" << endl;
        cout << "Weight " << r[id][2] << " Kg" << endl;
        cout << "Height " << r[id][3] << " meters" << endl;
    }
    int getid()
    {
        return membershipId;
    }
    void displayInfo() override
    {
        cout << "Regular Member - " << endl;
        Member::displayInfo();
        cout << "Membership ID: " << membershipId << endl;
    }
};
class PremiumMember : public RegularMember
{
private:
    string trainerName;

public:
    PremiumMember(){};
    PremiumMember(string n, int a, double w, double h, int d, string trainer) : RegularMember(n, a, w, h, d)
    {
        r[d].push_back(trainer);
        trainerName = trainer;
    }
    void ifexist(int id) override
    {
        cout << "Trainer " << r[id][4] << endl;
    }
    void displayInfo() override
    {
        cout << "Premium Member - " << endl;
        Member::displayInfo();
        cout << "Membership ID: " << getid() << endl;
        cout << "Trainer: " << trainerName << endl;
    }
};
class node // node class
{
    node *next;
    node *prev;
    long step_count;
    float cal;
    int sleep_count;
    int no_of_glasses;
    string workout;
    int day;

public:
    node() // constructor for initialising node fields
    {
        step_count = 0;
        cal = 0.0f;
        sleep_count = 0;
        no_of_glasses = 0;
        workout = "\0";
        next = NULL;
        prev = NULL;
        day = 0;
    }
    friend class p;
};
class p
{
    node *head;

public:
    p()
    {
        head = NULL;
    }

public:
    void accept_node(string name, long step_goal1, int water_intake_goal, int sleep_goal, int i);
    long step_goal(long);
    float calories();
    int sleep(int, string);
    int water(int);
    string workout();
    void display();
    void search(int);
    void search(long);
    void display_node(node *);
    void avg_analysis(long, int, int);
    void update();
    void line();
};
void p::accept_node(string name, long step_goal1, int water_intake_goal, int sleep_goal, int i)
{ // accepting node data fields
    cout << step_goal1 << endl;
    node *temp, *ptr;
    long steps_walked;
    steps_walked = step_goal(step_goal1);
    int water_taken = water(water_intake_goal);
    int sleep_taken = sleep(sleep_goal, name);
    float cal;
    cal = calories();
    string workout1;
    workout1 = workout();
    temp = new node(); // creating new node
    temp->step_count = steps_walked;
    temp->sleep_count = sleep_taken;
    temp->no_of_glasses = water_taken;
    temp->cal = cal;
    temp->workout = workout1;
    temp->day = i;
    // creation of List
    if (head == NULL) // if list is empty
    {
        head = temp;
    }
    else // adding nodes at the end of list
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
} // accept function ends
int p::water(int water_intake_goal) // defines water intake taken per day
{
    int water_intake;
    int flag = 1;
    cout << "Enter today's water intake : " << endl;
    cin >> water_intake;
    do
    {
        if (water_intake < 0 || water_intake > 25) // water intake validation starts
        {
            flag = 1;
            cout << "Please enter valid water intake : " << endl;
            cin >> water_intake;
        }
        else
        {
            flag = 0;
        }
    } while (flag == 1); // validation ends
    if (water_intake < water_intake_goal)
    {
        cout << "-----------------------------------------" << endl;
        cout << "You should increase your water intake :( " << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
    }
    if (water_intake >= water_intake_goal)
    {
        cout << "-----------------------------------------" << endl;
        cout << "Great!! You have accomplished your goal :) " << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
    }
    return water_intake;
} // water intake function ends
long p::step_goal(long step_goal) // Step count function which counts steps moved per day
{
    step_goal = step_goal + 2000;
    long step_count = (rand() % (step_goal - 400 + 1)) + 400; // use of rand function
    if (step_count >= step_goal)
    {
        cout << "-----------------------------------------" << endl;
        cout << "Great!! You have accomplished your goal :) " << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
    }
    else
    {
        cout << "-----------------------------------------" << endl;
        cout << "You should increase your step count   :( " << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
    }
    return step_count;
}
int p::sleep(int sleep_goal, string name) // No of hours slept
{
    int sleep_hours;
    int flag1 = 1;
    cout << "How much sleep did you take (in hours)?" << endl;
    cin >> sleep_hours;
    do // sleep time validation starts
    {
        if (sleep_hours < 0 || sleep_hours > 24)
        {
            flag1 = 1;
            cout << "Please enter valid sleep hours : " << endl;
            cin >> sleep_hours;
        }
        else
        {
            flag1 = 0;
        }
    } while (flag1 == 1);          // validation ends
    if (sleep_hours == sleep_goal) // if sleep time ==sleep goals set
    {
        cout << "----------------------------------" << endl;
        cout << name << ",Yay!!Sleep goals achieved!" << endl;
        cout << "----------------------------------" << endl;
        cout << endl;
    }
    if (sleep_hours < sleep_goal) // if sleep time< sleep goal set
    {
        cout << "----------------------------------" << endl;
        cout << name << ",you need more sleep!!" << endl;
        cout << "----------------------------------" << endl;
        cout << endl;
    }
    if (sleep_hours > sleep_goal) // if sleep time > sleep goal set
    {
        cout << "----------------------------------" << endl;
        cout << name << ",too much sleep!!" << endl;
        cout << "----------------------------------" << endl;
        cout << endl;
    }
    return sleep_hours;
} // end of function
float p::calories() // Counts calories based on food had in 24 hrs
{
    int a, flag2;
    char ch;
    float calories = 0.0, cal1;
    do
    { // Generalised food option categories having average calories per quantity eaten
        cout << "FOOD OPTIONS:\n1.Pulse/Grains?" << endl;
        cout << "2.Fruits?" << endl;
        cout << "3.Vegetables?" << endl;
        cout << "4.Junk Food?" << endl;
        cout << "Choose Food option" << endl;
        cin >> a;
        do // validation of choosing option starts
        {
            if (a < 1 || a > 4)
            {
                flag2 = 1;
                cout << "Please enter valid food option" << endl;
                cin >> a;
            }
            else
            {
                flag2 = 0;
            }
        } while (flag2 == 1); // validation ends
        switch (a)
        { // assigning calories to meal eaten
        case 1:
            if (a == 1)
            {
                cal1 = 200;
            }
            break;
        case 2:
            if (a == 2)
            {
                cal1 = 100;
            }
            break;
        case 3:
            if (a == 3)
            {
                cal1 = 100;
            }
            break;
        case 4:
            if (a == 4)
            {
                cal1 = 800;
            }
            break;
        }                           // switch ends here
        calories = calories + cal1; // adding total calories based on total no of meals taken
        cout << "Did you eat anything else(y/n)??" << endl;
        cin >> ch;
    } while (ch == 'y');
    return calories; // returning total calories
}
string p::workout() // Workout done in a day
{
    string str, str1 = "\0";
    int workout;
    int flag = 0;

    cout << "WORKOUT OPTIONS: "
            "1. Swimming\n"
            "2. Walking\n"
            "3. Treadmill\n"
            "4. Elliptical training\n"
            "5. Weight training\n"
            "6. Running\n"
            "7. Cycling\n"
            "8. Hiking\n"
            "9. Aerobics\n"
            "10. NA\n";

    cout << "Enter your choice" << endl;
    cin >> workout;
    if (workout < 1 || workout > 10)
    {
        cout << "Invalid choice" << endl;
    }
    while (workout < 1 || workout > 10)
        ; // validation ends
    switch (workout)
    {
    case 1:
        str = "Swimming";
        break;
    case 2:
        str = "Walking";
        break;
    case 3:
        str = "Treadmill";
        break;
    case 4:
        str = "Elliptical";
        break;
    case 5:
        str = "Weight Training";
        break;
    case 6:
        str = "Running";
        break;
    case 7:
        str = "Cycling";
        break;
    case 8:
        str = "Hiking";
        break;
    case 9:
        str = "Aerobics";
        break;
    case 10:
        str = "NA";
        break;
    }
    return str;
} // workout function ends
void p::line() // function used for dislaying in tabular format
{
    for (int i = 1; i < 50; i++)
        cout << "--";

    cout << "\n";
}
void p::display() // displaying details of all day
{
    node *ptr;

    if (head == NULL)
    {
        cout << "list is empty" << endl;
    }

    cout << "\n\n\n";
    cout << setw(52) << "FITNESS TRACKING SYSTEM\n";
    line();
    cout << "DAY" << setw(15) << "WATER INTAKE" << setw(15) << "SLEEP TIME " << setw(15) << "STEPS" << setw(20) << "WORKOUT" << setw(20) << "CALORIES\n";
    line();
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->day == 0)
        {
            break;
        }
        else
        {
            cout << ptr->day << setw(12) << ptr->no_of_glasses << setw(12) << ptr->sleep_count << setw(20) << ptr->step_count << setw(20) << ptr->workout << setw(20) << ptr->cal << endl;
        }
    }
}
void p::search(int day) // Searching a node based on day no
{
    cout << "1 " << day << endl;
    int flag = 0;
    node *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (day == ptr->day)
        {
            flag = 1;
            display_node(ptr);
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Day not found" << endl;
    }
}
void p::search(long value) // Searching based on min steps achieved
{
    cout << "2" << endl;
    int flag = 0;
    node *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->step_count >= value) // displays all the days which achieved the min stepcount value
        {
            flag++;
            display_node(ptr);
        }
    }
    if (flag == 0) // if no milestone achieved
    {
        cout << "Oops!You haven't achieved these milestones" << endl;
    }
}
void p::display_node(node *ptr) // displaying details of one node
{

    cout << "***************************" << endl;
    cout << "DAY " << ptr->day << endl;
    cout << "WATER INTAKE : " << ptr->no_of_glasses << endl;
    cout << "SLEEP TIME :" << ptr->sleep_count << endl;
    cout << "STEPS: " << ptr->step_count << endl;
    cout << "WORKOUT:" << ptr->workout << endl;
    cout << "CALORIES:" << ptr->cal << endl;
    cout << "***************************" << endl;
}
void p::avg_analysis(long step_count1, int sleep_count, int water_count) // Average Analaysis of all the days
{
    node *ptr;
    ptr = head;
    int i = 0;
    long avg_step_count = 0;
    float avg_cal = 0.0f;
    float avg_sleep_count = 0;
    float avg_no_of_glasses = 0;
    if (head == NULL)
    {
        cout << "List is empty.";
    }
    else
    {
        while (ptr != NULL)
        {
            i++;
            avg_step_count += ptr->step_count;
            avg_cal += ptr->cal;
            avg_sleep_count += ptr->sleep_count;
            avg_no_of_glasses += ptr->no_of_glasses;
            ptr = ptr->next;
        }
        avg_step_count /= i;
        avg_cal /= i;
        avg_sleep_count /= i;
        avg_no_of_glasses /= i;
        cout << setw(50) << "AVERAGE ANALYSIS" << endl;
        // display average analysis
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Avg. step count(steps):\t "
             << "Avg. calories consumed(cal):\t  "
             << "Avg. sleep taken(in hrs):      "
             << "Avg. water intake(in glasses):" << setw(10) << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << avg_step_count << setw(30) << avg_cal << setw(30) << avg_sleep_count << setw(30) << avg_no_of_glasses << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        if (avg_step_count >= step_count1)
        {
            cout << "***STEP GOALS***" << endl;
            cout << "Hurray,Goals achieved" << endl;
            cout << endl;
        }
        else
        {
            cout << "***STEP GOALS***" << endl;
            cout << "You need to walk more often!!" << endl;
            cout << endl;
        }
        if (avg_sleep_count >= sleep_count)
        {
            cout << "***SLEEP TIME***" << endl;
            cout << "Hurray,your sleep time is good!" << endl;
            cout << endl;
        }
        else
        {
            cout << "***SLEEP TIME***" << endl;
            cout << "You need to have good sleep for healthy life!!" << endl;
            cout << endl;
        }
        if (avg_no_of_glasses >= water_count)
        {
            cout << "***WATER INTAKE***" << endl;
            cout << "Hurray,Goals achieved!!" << endl;
            cout << endl;
        }
        else
        {
            cout << "***WATER INTAKE***" << endl;
            cout << "You need to drink water more often!!" << endl;
            cout << endl;
        }
        if (avg_cal >= 1000)
        {
            cout << "***CALOREIS***" << endl;
            cout << "You need to exercise more to burn calories" << endl;
            cout << endl;
        }
        else
        {
            cout << "***CALORIES***" << endl;
            cout << "Hurray,your diet is perfect!!" << endl;
        }
    }
}
void p::update() // Updating data fields based on workout and water intake
{
    node *ptr;
    int x;
    ptr = head;
    string workout1;
    string str;
    int no_of_glasses1;
    int day1;
    cout << "Enter number of day to update ";
    cin >> day1;
    if (head == NULL) // validation for updating a node begins
    {
        cout << "\nList is already empty. Cannot update a node";
    } // validation for updating a node ends
    else
    {
        for (ptr = head; ptr != NULL; ptr = ptr->next) // updating day details
        {
            if (ptr->day == day1)
            {
                do
                {
                    cout << "\n\nEnter 1 for updating workout" << endl;
                    cout << "Enter 2 for updating water intake" << endl;
                    cout << "Enter 3 to exit from update " << endl;
                    cout << "\nEnter your choice " << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                        int c;
                        //  do
                        // {
                        cout << "\nWORKOUT OPTIONS: "
                                "1. Swimming\n"
                                "2. Walking\n"
                                "3. Treadmill\n"
                                "4. Elliptical training\n"
                                "5. Weight training\n"
                                "6. Running\n"
                                "7. Cycling\n"
                                "8. Hiking\n"
                                "9. Aerobics\n";
                        "10. NA\n";
                        cout << "\nEnter updated workout " << endl;
                        cin >> c;
                        switch (c)
                        {
                        case 1:
                            str = "Swimming";
                            break;
                        case 2:
                            str = "Walking";
                            break;
                        case 3:
                            str = "Treadmill";
                            break;
                        case 4:
                            str = " Elliptical";
                            break;
                        case 5:
                            str = "Weight training";
                            break;
                        case 6:
                            str = "Running";
                            break;
                        case 7:
                            str = "Cycling";
                            break;
                        case 8:
                            str = "Hiking";
                            break;
                        case 9:
                            str = "Aerobics";
                            break;
                        case 10:
                            str = "NA";
                            break;
                        }                   // switch ends here
                                            //  cout<<"\n\nDid you do any other workout(y/n)?";
                                            // cin>>ans;
                                            // }while(ans=='y');
                        ptr->workout = str; // contents of string are stored in datafield of node of list
                                            //  cout<<ptr->workout;
                        break;
                    case 2:
                        cout << "\nEnter updated water intake in glasses " << endl;
                        cin >> no_of_glasses1;
                        ptr->no_of_glasses = ptr->no_of_glasses + no_of_glasses1; // adding no of glasses to existing glass count
                        cout << "Your new water intake is"
                             << " " << ptr->no_of_glasses;
                        break;
                    case 3:
                        break;
                    } // switch case ends here
                } while (x != 3);
            }
        }

    } // else loop ends here
}
string checkbmi(double weight, double height)
{
    string s;
    double BMI = (weight) / (height * height);
    cout << "Your BMI is " << BMI << endl;
    if ((BMI) < 18.5)
    {
        s = "Underweight";
    }
    else if ((BMI) >= 18.5 && (BMI) <= 24.9)
    {
        s = "Healthy";
    }
    else if ((BMI) >= 25.0 && (BMI) <= 29.9)
    {
        s = "Overweight";
    }
    else
    {
        s = "Obese";
    }
    return s;
}
int main()
{
    cout << "                                                                    ______     ______    _________     _________  " << endl;
    cout << "                                                                   |  __  |   |  ____|  |  _   _  |   |  _   _  | " << endl;
    cout << "                                                                   |_|  | |   | |____   |_/ | | \\_|   |_/ | | \\_|" << endl;
    cout << "                                                                    ____| |   |  ____|      | |           | |     " << endl;
    cout << "                                                                   |  ____|   | |        _  | |  _        | |     " << endl;
    cout << "                                                                   | |____    | |       | \\_| |_/ |       | |     " << endl;
    cout << "                                                                   |______|   |_|       |_________|       |_|     " << endl;
    cout << endl
         << endl;
    int sleep_goal = 0;
    int water_intake_goal = 0;
    long step_goal1 = 0;
    map<int, vector<long>> goals;
    vector<p> l(100000);
    unordered_map<int, int> mp;
    map<int, string> mp1;
    int id1 = 1;
    do
    {
        int n = 4;
        cout << "Enter 1 to Sign in in app" << endl;
        cout << "Enter 2 to  Create an new account" << endl;
        cout << "Enter 3 to delete the existing account" << endl;
        cout << "Enter any other key to exit the app" << endl;
        cin >> n;
        if (n == 1)
        {
            string s;
            int x, id;
            cout << "press 1 if you are regular member" << endl;
            cout << "press 2 if you are premimum user" << endl;
            cin >> x;
            cout << "enter your id and name for login" << endl;
            cin >> id;
            cin.ignore();
            getline(cin, s);
            if (x == 1)
            {
                if (mp1[id] == s)
                {
                    int y = 7;
                    if (mp[id])
                    {
                        cout << "Welcome back " << s << endl;
                        char z;
                        cout << "press 1 to rest the goals" << endl;
                        cout << "press any key to continue" << endl;
                        cin >> z;
                        if (z == '1')
                        {
                            goals[id] = {};
                            mp[id] = 0;
                        }
                    }
                    if (!mp[id])
                    {
                        mp[id]++;
                        cout << "Welcome " << s << endl;
                        cout << "set the goals for your journey" << endl;
                        do
                        {
                            cout << "Enter the value for sleep goal in hours" << endl;
                            cin >> sleep_goal;
                            if (sleep_goal <= 0 || sleep_goal >= 24)
                            {
                                cout << "Enter the valid Sleep Goal" << endl;
                            }
                        } while (sleep_goal <= 0 || sleep_goal >= 24);
                        do
                        {
                            cout << "Enter the value for water intake goal in glasses" << endl;
                            cin >> water_intake_goal;
                            if (water_intake_goal <= 0 || water_intake_goal >= 30)
                            {
                                cout << "Enter the valid water intake goal" << endl;
                            }
                        } while (water_intake_goal <= 0 || water_intake_goal >= 30);
                        do
                        {
                            cout << "Enter the value for step goal" << endl;
                            cin >> step_goal1;
                            if (step_goal1 <= 100 || step_goal1 >= 300000)
                            {
                                cout << "Enter the valid step goal" << endl;
                            }
                        } while (step_goal1 <= 100 || step_goal1 >= 300000);
                        goals[id].push_back(step_goal1);
                        goals[id].push_back(water_intake_goal);
                        goals[id].push_back(sleep_goal);
                    }
                    do
                    {
                        cout << "----------Menu---------" << endl;
                        cout << "1.Accept Daily details related to your Goals" << endl;
                        cout << "2.Display Daily details related to your Goals" << endl;
                        cout << "3.Search a day" << endl;
                        cout << "4.Update details for a day" << endl;
                        cout << "5.Average Analysis" << endl;
                        cout << "6.EXIT" << endl;
                        cin >> y;
                        if (y == 1)
                        {
                            int no_of_days = 0;
                            cout << "Enter number of days for which you want to enter data" << endl;
                            cin >> no_of_days;
                            do
                            {
                                if (no_of_days <= 0 || no_of_days > 7)
                                {
                                    cout << "Invalid day: " << endl;
                                    cout << "Enter number of days for which you want to enter data" << endl;
                                }
                            } while (no_of_days <= 0 || no_of_days > 7);
                            for (int i = 1; i <= no_of_days; i++)
                            {
                                cout << "DAY:" << i << endl;
                                l[id].accept_node(s, goals[id][0], goals[id][1], goals[id][2], i);
                                cout << endl;
                            }
                        }
                        else if (y == 2)
                        {
                            l[id].display();
                        }
                        else if (y == 3)
                        {
                            int value;
                            long step = 0;
                            char c;
                            cout << "Enter 1 for searching a day based on day number" << endl;
                            cout << "Enter any other key for searching a day based on  minimum step" << endl;
                            cin >> c;
                            if (c == '1')
                            {
                                cout << "Enter day for searching data " << endl;
                                cin >> value;
                                l[id].search(value);
                            }
                            else
                            {
                                cout << "Enter the minimum step count for searching day " << endl;
                                cin >> step;
                                l[id].search(step);
                            }
                        }
                        else if (y == 4)
                        {
                            l[id].update();
                        }
                        else if (y == 5)
                        {
                            l[id].avg_analysis(goals[id][0], goals[id][1], goals[id][2]);
                        }
                        else
                        {
                            break;
                        }
                    } while (1);
                }
                else
                {
                    cout << "Enter Valid Id and Name and try agian" << endl;
                }
            }
            else if (x == 2)
            {
                if (mp1[id] == s)
                {
                    if (mp[id])
                    {
                        cout << "Welcome back " << s << endl;
                        char z;
                        cout << "press 1 to rest the goals" << endl;
                        cout << "press any key to continue" << endl;
                        cin >> z;
                        if (z == '1')
                        {
                            goals[id] = {};
                            mp[id] = 0;
                        }
                    }
                    if (!mp[id])
                    {
                        mp[id]++;
                        cout << "Welcome " << s << endl;
                        cout << "set the goals for your journey" << endl;
                        do
                        {
                            cout << "Enter the value for sleep goal in hours" << endl;
                            cin >> sleep_goal;
                            if (sleep_goal <= 0 || sleep_goal >= 24)
                            {
                                cout << "Enter the valid Sleep Goal" << endl;
                            }
                        } while (sleep_goal <= 0 || sleep_goal >= 24);
                        do
                        {
                            cout << "Enter the value for water intake goal in glasses" << endl;
                            cin >> water_intake_goal;
                            if (water_intake_goal <= 0 || water_intake_goal >= 30)
                            {
                                cout << "Enter the valid water intake goal" << endl;
                            }
                        } while (water_intake_goal <= 0 || water_intake_goal >= 30);
                        do
                        {
                            cout << "Enter the value for step goal" << endl;
                            cin >> step_goal1;
                            if (step_goal1 <= 100 || step_goal1 >= 300000)
                            {
                                cout << "Enter the valid step goal" << endl;
                            }
                        } while (step_goal1 <= 100 || step_goal1 >= 300000);
                        goals[id].push_back(step_goal1);
                        goals[id].push_back(water_intake_goal);
                        goals[id].push_back(sleep_goal);
                    }
                    do
                    {
                        int y = 7;
                        cout << "----------Menu---------" << endl;
                        cout << "1.Accept Daily details related to your Goals" << endl;
                        cout << "2.Display details related to your Goals" << endl;
                        cout << "3.Search a day " << endl;
                        cout << "4.Update details for a day" << endl;
                        cout << "5.Average Analysis" << endl;
                        cout << "6.EXIT" << endl;
                        cin >> y;
                        if (y == 1)
                        {
                            int no_of_days = 0;
                            cout << "Enter number of days for which you want to enter data" << endl;
                            cin >> no_of_days;
                            do
                            {
                                if (no_of_days <= 0 || no_of_days > 7)
                                {
                                    cout << "Invalid day: " << endl;
                                    cout << "Enter number of days for which you want to enter data" << endl;
                                }
                            } while (no_of_days <= 0 || no_of_days > 7);
                            for (int i = 1; i <= no_of_days; i++)
                            {
                                cout << "DAY:" << i << endl;
                                l[id].accept_node(s, goals[id][0], goals[id][1], goals[id][2], i);
                                cout << endl;
                            }
                        }
                        else if (y == 2)
                        {
                            l[id].display();
                        }
                        else if (y == 3)
                        {
                            int value;
                            long step = 0;
                            char c;
                            cout << "Enter 1 for searching a day based on day number" << endl;
                            cout << "Enter any other key for searching a day based on  minimum step" << endl;
                            cin >> c;
                            if (c == '1')
                            {
                                cout << "Enter day for searching data " << endl;
                                cin >> value;
                                l[id].search(value);
                            }
                            else
                            {
                                cout << "Enter the minimum step count for searching day " << endl;
                                cin >> step;
                                l[id].search(step);
                            }
                        }
                        else if (y == 4)
                        {
                            l[id].update();
                        }
                        else if (y == 5)
                        {
                            l[id].avg_analysis(goals[id][0], goals[id][1], goals[id][2]);
                        }
                        else
                        {
                            break;
                        }
                    } while (1);
                }
                else
                {
                    cout << "Enter Valid Id and Name and try agian" << endl;
                }
            }
            else
            {
                cout << "Invalid Operation" << endl;
            }
        }
        else if (n == 2)
        {
            string name;
            int age;
            double weight, height;
            cout << "Enter Your name" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter Your age" << endl;
            cin >> age;
            cout << "Enter Your weight in kg:" << endl;
            cin >> weight;
            cout << "Enter Your height in meters:" << endl;
            cin >> height;
            string s;
            s = checkbmi(weight, height);
            cout << "Your are " << s << endl;
            if (s == "Underweight")
            {
                cout << "Recommanded for Weight gain + weight training" << endl;
            }
            else if ("Healthy")
            {
                cout << "Recommnaded for weight training" << endl;
            }
            else
            {
                cout << "Recommanded for weight loss + weight training" << endl;
            }

            int x;
            cout << "press 1 for regular membership" << endl;
            cout << "press 2 for premimum membership" << endl;
            cin >> x;
            if (x == 1)
            {
                RegularMember rm(name, age, weight, height, id1);
                mp1[id1] = name;
                id1++;
                rm.displayInfo();
                cout << "Hey,congragulations you just got regular subcrpition of 2 fit we wish you great journey" << endl;
            }
            else
            {
                vector<string> a = {"", "Ronnie Coleman", "Arnold Schwarzenegger", "Jay Cutler", "Sergio Oliva", "Frank Zane", "Larry Scott"};
                x = -1;
                do
                {
                    cout << "Trainer's You want select their s.no" << endl;
                    cout << "---------------------------------" << endl;
                    cout << "1.Ronnie Coleman                |" << endl;
                    cout << "2.Arnold Schwarzenegger         |" << endl;
                    cout << "3.Jay Cutler                    |" << endl;
                    cout << "4.Sergio Oliva                  |" << endl;
                    cout << "5.Frank Zane                    |" << endl;
                    cout << "6.Larry Scott                   |" << endl;
                    cout << "---------------------------------" << endl;
                    cin >> x;
                    if (x <= 0 || x > 6)
                    {
                        cout << "Invalid trainer name,plz enter the tariner name carefully!!" << endl;
                    }
                } while (x <= 0 || x > 6);
                PremiumMember pm(name, age, weight, height, id1, a[x]);
                mp1[id1] = name;
                id1++;
                pm.displayInfo();
                cout << "Hey,congragulations you just got perimum subcrpition of 2 fit we wish you great journey" << endl;
            }
            cout << "Now Login with your id and name for starting journey" << endl;
        }
        else if (n == 3)
        {
            string s;
            int id;
            cout << "Enter your id and name to delete the account" << endl;
            cin >> id >> s;
            if (r[id][0] == s)
            {
                r[id] = {""};
                cout << "Your account was sucessfully deleted" << endl;
            }
            else
            {
                cout << "This type of account doesn't exist plz try other account" << endl;
            }
        }
        else
        {
            break;
        }
    } while (1);
    cout << "Thank's for Visiting!!" << endl;
    return 0;
}