#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <fstream>
using namespace std;

string caesar_encryption(string s, int shift)               // operator for encryptin our text
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            s[i] = ((s[i] - 'A') + shift) % 26 + 'A';       //%26 to prevent errors when shift >26
        }
        else if (islower(s[i]))
        {
            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';       //%26 to prevent errors when shift >26
        }
    }
    return s;
}

string caesar_decryption(string s, int shift)               //operator for decryption
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            s[i] = ((s[i] - 'A' - shift + 26) % 26) + 'A';          //%26 to prevent errors when shift >26
        }
        else if (islower(s[i]))
        {
            s[i] = ((s[i] - 'a' - shift + 26) % 26) + 'a';      //%26 to prevent errors when shift >26
        }
    }
    return s;
}

string convert_from_ASCII(const vector<int>& indices) 
{
    string str;
    for (int index : indices) {
        str.push_back(static_cast<char>(index));            //storing our string in vector for better operating after
    }
    return str;
}

string convert_to_string(const string& input)
{
    stringstream ss(input);
    string result;
    int ascii_value;
    while (ss >> ascii_value) {
        result += static_cast<char>(ascii_value);       //transforming into characters
    }
    return result;
}

vector<int> convert_to_ASCII(const string& str) 
{
    vector<int> indices;
    for (char c : str) 
    {
        indices.push_back(static_cast<int>(c));
    }
    return indices;
}

int main()
{
    ifstream text_input;
    ifstream shift_input;
    ifstream choice_input;
    ofstream fout("output.txt");
    text_input.open("text3.txt");
    string text_to_encrypt;
    int encryption_shift, user_choice;
    cout << "Enter the string: ";
    getline(text_input, text_to_encrypt); 
    text_input.close();
    cout << "Enter 1 for encryption or 2 for decryption in Caesar Encryption Method. Enter 3 for encryption and 4 for decryption in ASCII Table Encryption Method\n";
    choice_input.open("choice3.txt");
    while(true)
    {
        choice_input>>user_choice;
        if (choice_input.eof())
            break;
    }
    choice_input.close();
    cout << "You choose: " << user_choice << endl;
    if (user_choice == 1)
    {
        cout << "Enter the shift value: ";
        shift_input.open("shift1.txt");
        while(true)
        {
            shift_input>>encryption_shift;
            if (shift_input.eof())
                break;
        }
        shift_input.close();
        cout << encryption_shift;
        cout << endl;
        fout << "Encrypted text: " << caesar_encryption(text_to_encrypt, encryption_shift);
        cout << "Encrypted text: " << caesar_encryption(text_to_encrypt, encryption_shift);
    }
    else if (user_choice == 2)
    {
        cout << "Enter the shift value: ";
        shift_input.open("shift2.txt");
        while(true)
        {
            shift_input>>encryption_shift;
            if (shift_input.eof())
                break;
        }
        cout << encryption_shift;
        cout << endl;
        fout << "Decrypted text: " << caesar_decryption(text_to_encrypt, encryption_shift);
        cout << "Decrypted text: " << caesar_decryption(text_to_encrypt, encryption_shift);
    }
    else if(user_choice==3)
    {
        vector<int> asciiIndices = convert_to_ASCII(text_to_encrypt);
        cout << "ASCII Indices of characters in \"" << text_to_encrypt << "\": ";
        for (int index : asciiIndices) 
        {
            fout << index << " ";
            cout << index << " ";
        }
        cout<<endl;
    }
    else if(user_choice==4)
    {
        string decrypted_text = convert_to_string(text_to_encrypt);
        fout << "Decrypted text: " << decrypted_text << endl;
        cout << "Decrypted text: " << decrypted_text << endl;
    }
    else
    {
        fout << "Invalid choice!";
        cout << "Invalid choice!";
    }
    return 0;
}
