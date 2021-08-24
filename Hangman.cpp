#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
 
using namespace std;

class HangMan{

    private:

    // our private variable that contains how many times the user has guessed wrong
    int chances;

    public:

    // a coustructor that initalizes our chances to 0 when we delare the a hangman variable
    HangMan(){
        chances = 0;
    }
    // an array that contains a list of countries from which we will randomly select one
    string words[60] = {"PAKISTAN", "AFGHANISTAN", "ALBANIA", "ALGERIA", "ARGENTINA", "AUSTRALIA", "BALNGLADESH", "BELARUS", "BELGIUM", "BOLOVIA",
    "BRAZIL", "CAMBODIA", "CANADA", "CHINA", "COLONBIA", "EGYPT", "FINLAND", "FRANCE", "GEORGIA", "GERMANY", "GREECE", "HUNGARY", "ICELAND",
    "INDIA", "IRAN", "IRAQ", "IRELAND", "ISRAEL", "ITALY", "JAPAN", "JORDAN", "KAZAKHSTAN", "LEBANON", "LYBIA", "MADAGASCAR", "MALAYSIA",
    "MALTA", "MEXICO", "MOROCCO", "NEPAL", "NETHERLANDS", "NIGERIA", "PAKISTAN", "POLAND", "PORTUGAL", "QATAR", "RUSSIA", "SINGAPORE",
    "SLOVENIA", "SPAIN", "SWEDEN", "SWITZERLAND", "THAILAND", "TURKEY", "UKRAINE", "AMERICA", "UZBEKISTAN", "VEITNAM", "YEMEN", "ZIMBABWE"};
    // an array that prints out the blanks according to the legnth of the country selected
    char word[40] = {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'
    , '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'};
    // an array which will display the available letters and be used as a check to see if the input letter was not selected before
    char available_letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z'};
    // a variable that will store the random word that we selected
    string selected_word;

    // function that displays our welcoming message at the top most of the console
    void print_staring_message(){
        cout << "Welcome to Hang-Man!" << endl;
        cout << "Good Luck and Have Fun!" << endl;
        cout << endl << endl;
    }

    // function that resets our array of underscores back to its orignal form
    void reset_blanks(){
        for (int i = 0; i < 40; i++){
            word[i] = '_';
        }
    }

    // function that resets our array of letters to be picked from back to its orignal form
    void reset_available_letters(){
        int j = 0;
        for (int i = 0; i < 26; i++){
        available_letters[i] = static_cast<char>(65 + j);
        j++;
        }
    }
    
    // function that resets our chances back to its zero value
    void reset_chances(){
        update_chances(0);
    }

    // function that will return the selected word
    string return_selected_word(){
        return selected_word;
    }

    // function that will display all the available letters to the console
    void display_letters(){
        cout << "The Letters Available To Choose From Are As Shown Below! (Please Enter It As A Capital Letter)" << endl;
        for (int i = 0; i < 26; i++){
            cout << available_letters[i] << " ";
        }
        cout << endl;
    }

    // function that will help us in selecting a random word from our array 
    void get_random_word(){
        srand(time(0));     // use of time function to get a random country every time the game is played
        selected_word = words[rand() % 60];     // selecting a country from our array in the index 0 - 60
    }

    // function that will update our private variable chances
    void update_chances(int c){
        this -> chances = c;
    }

    // function that will increase the number of chances the user has upon entering a wrong input
    void inc_chances(){
        int c;
        c = get_chances() + 1;
        update_chances(c);
    }

    // function that will check if all the words have been guessed (game has been won)
    int check_win(){
        int check;
        for (int i = 0; i < string_legnth(selected_word); i++){
            if (word[i] == '_'){
                check = 0;
                break;
            }
            else{
                check = 1;
            }
        }
        return check;
    }

    // function that will check if the player has ran out of all his 8 chances
    int check_lose(){
        int check;
        if (get_chances() == 8){
            return 1;
        }
        else{
            return 0;
        }
    }

    // function in which we will take a input letter and perform various checks 
    void get_input(){
        char letter;
        int found = 0;      // variable used as a checking flag to see if the letter was contained in the random word
        int where_found;    
        int check = 0;      // varible that will be used as a check to test if the letter was not selected before
        int available = 1;      // variable to display the error message to know what the user did wrong
        do{
            if (available == 0){
                cout << "You entered a letter that is not available! Please try again!" << endl;
                cout << "Make sure the letter you enter is a capital letter!" << endl;
            }
            cout << "Enter a letter to guess the word!" << endl;
            cin >> letter;
            // loop to check if the letter was selected before or not
            for (int i = 0; i < 26; i++){
                if(available_letters[i] == letter){
                    check = 1;
                    available = 1;
                }
                else{
                    available = 0;
                }
            }
        } while (check == 0);
        // loop to update the blanks and place the right guessed letter
        for (int i = 0; i < string_legnth(selected_word); i++){
            if (selected_word[i] == letter){
                found = 1;
                where_found = i;
                word[where_found] = letter;
            }
            // loop to remove the right guessed letter from the letters available to be guessed
            for (int j = 0; j < 26; j++){
                if (available_letters[j] == letter){
                    available_letters[j] = ' ';
                }
            }        
        }
        // if the letter entered was not the right guess increase the number of times the user has guessed wrongly
        if (found == 0){
            inc_chances();
        }
    }

    // function to get the value in our private variable chances
    int get_chances(){
        return chances;
    }
    
    // function that draws the blanks according to the number of letters in the random word
    void draw_blanks(){
        for (int i = 0; i < string_legnth(selected_word); i++){
            cout << word[i] << " ";
        }
        cout << endl;
    }

    // function that returns the number of letters of the word that was passed as a argument
    int string_legnth(string s){
        int legnth;
        for (int i = 0; i < 20; i++){
           if (s[i] == '\0'){
               legnth = i;
               break;
           }
        }
        return legnth;
    }

    // function that draws our hangman and display the tries the user has left according to the amount of times he has guessed wrong
    void draw_hangman(){
        if (get_chances() == 0){
            cout << endl << endl << endl << endl << endl;
            cout << "You Have 8 Chance's Left" << endl;
        }
        else if (get_chances() == 1){
        cout << "\t( " << endl;
        cout << endl << endl << endl << endl;
        cout << "You Have 7 Chance's Left" << endl;     
        }
        else if (get_chances() == 2){
        cout << "\t( )" << endl;
        cout << endl << endl << endl << endl;
        cout << "You Have 6 Chance's Left" << endl; 
        }
        else if (get_chances() == 3){
        cout << "\t( )" << endl;
        cout << "\t/" << endl;
        cout << endl << endl << endl;
        cout << "You Have 5 Chance's Left" << endl;           
        }
        else if (get_chances() == 4){
        cout << "\t( )" << endl;
        cout << "\t/|" << endl;
        cout << endl << endl << endl;
        cout << "You Have 4 Chance's Left" << endl;         
        }
        else if (get_chances() == 5){
        cout << "\t( )" << endl;
        cout << "\t/|\\" << endl;
        cout << endl << endl << endl;
        cout << "You Have 3 Chance's Left" << endl;      
        }
        else if (get_chances() == 6){
        cout << "\t( )" << endl;
        cout << "\t/|\\" << endl;
        cout << "\t |" << endl;
        cout << endl << endl;
        cout << "You Have 2 Chance's Left" << endl;            
        }
        else if (get_chances() == 7){
        cout << "\t( )" << endl;
        cout << "\t/|\\" << endl;
        cout << "\t |" << endl;
        cout << "\t/" << endl;
        cout << endl;
        cout << "You Have 1 Chance Left" << endl;       
        }
        else if (get_chances() == 8){
        cout << "\t( )" << endl;
        cout << "\t/|\\" << endl;
        cout << "\t |" << endl;
        cout << "\t/ \\"<< endl;
        cout << endl;
        cout << "You Have 0 Chance's Left" << endl;
        }
    }

    // function that will start our game and also terminate when the user does not want to play more
    void play_game(){
        // variables that will be used as checks for error handling to check if the game is over
        int win;
        int lose;
        bool game_end = true;
        char Y_or_N;    // variable that will take input the users choice to play again or not and be checked using conditions
        int again = 0;
        int wrong_again = 0;
    
        do{
            // getting a random word
            get_random_word();
            // resetting all of our variables (both class and bollean check) in case the user wants to play again
            reset_blanks();
            reset_available_letters();
            reset_chances();
            lose = 0;
            win = 0;
            game_end = true;
            wrong_again = 0;
            again = 0;

            // loop the keep the game running until the user wins or loses
            while(game_end){
                system("CLS");  // clearing the screen everytime the user makes a guess
                print_staring_message();
                display_letters();
                draw_hangman();
                draw_blanks();
                get_input();
                win = check_win();
                if (win == 1){
                    game_end = false;
                }
                lose = check_lose();
                if (lose == 1){
                    game_end = false;
                }
            }
            // condition to check if the user had lost then what to print
            if (lose == 1){
                system("CLS");      // clearing the screen to print the losing message
                display_letters();
                draw_hangman();
                cout << "GAME OVER!" << endl;
                cout << "YOU LOST !" << endl << "THE WORD WAS = " << return_selected_word() << endl;

            }
            // condition to check if the user had won then what to print
            if (win == 1){
                system("CLS");      // clearing the screen to print the winning message
                display_letters();
                draw_hangman();
                cout << "GAME OVER!" << endl;
                cout << "YOU WON !" << endl << "THE WORD WAS = " << return_selected_word() << endl;
            }
            // loop in which we check if the user wants to play again and entered a valid input
            do{
                if (wrong_again == 1){
                    cout << "Invalid Input!, Please Try Again!" << endl;
                }
                cout << "Do you want to play again?"<< endl << "Enter Y for Yes!" << endl << "Enter N for No!" << endl;
                cin >> Y_or_N;
                if (Y_or_N == 'y' || Y_or_N == 'Y'){
                    again = 1;
                    wrong_again = 0;
                }
                else if (Y_or_N == 'n' || Y_or_N == 'N'){
                    again = 0;
                    wrong_again = 0;
                }
                else{
                    wrong_again = 1;
                }
            } while (wrong_again == 1);
    
        } while (again == 1);
    }
};

int main(){
    // creating an object of our hangman class
    HangMan h1;
    // calling the play game function of our hangman object that will run the game
    h1.play_game();

    // displaying the ending message to the user that he may press any key to close the black box
    cout << endl;
    system("PAUSE");
    return 0;
}
