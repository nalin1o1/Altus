// classifies the different tokens.
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "tokenizer.hpp"

using namespace std;

class identify
{
	tkn obj;
	
public:
	vector<string> classify(vector <string> tokenized)
	{
		vector <string> types{ "seperator","word","keyword","operator","identifier"};
		
		vector<string>keyword{ "False", "None", "True", "and", "as", "assert", "async", "await", "break",
		"class", "continue", "def", "del", "elif", "else", "except", "finally",
		"for", "from", "global", "if", "import", "in", "is", "lambda", "nonlocal",
		"not", "or", "pass", "raise", "return", "try", "while", "with", "yield" };

		vector<string>operators{
            // Arithmetic Operators
            "+", "-", "*", "/", "%", "**", "//",
            // Assignment Operators
            "=", "+=", "-=", "*=", "/=", "%=", "//=", "**=", "&=", "|=", "^=", ">>=", "<<=",
            // Comparison Operators
            "==", "!=", ">", "<", ">=", "<=",
            // Logical Operators
            "and", "or", "not",
            // Identity Operators
            "is", "is not",
            // Membership Operators
            "in", "not in",
            // Bitwise Operators
            "&", "|", "^", "~", "<<", ">>"
        };

        vector <string> seperator{ "(", ")", "[", "]", "{", "}", ",", ":", ".", ";", "@",  "->"};

        vector <string> cla_line;
        // token classifier.
        for (int x = 0; x < tokenized.size(); x++)
        {
            int counter = 0;
            string word = tokenized.at(x);
            for (int y = 0;y < keyword.size(); y++)
            {
                if (word[0] == '"')
                {
                    cla_line.push_back("string");
                    goto jump;
                }
                if (word == keyword.at(y))
                {
                    cla_line.push_back("keyword");
                    goto jump;
                 
                   
                }
            }
            
            if (word == "=")
            {
                cla_line.push_back("assignment");
                goto jump;
            }
            for (int y = 0; y < operators.size();y++)
            {
              
                if (word == operators.at(y))
                {
                    cla_line.push_back("operator");
                    goto jump;
                   
                }
            }
            for (int y = 0; y < seperator.size();y++)
            {
                if (word == seperator.at(y))
                {
                    cla_line.push_back("seperator");
                    goto jump;
                   
                }
            }
            if (counter == 0)
            {
                cla_line.push_back(word_check(word));
            }
            
        jump:;
           
        }
       
        return(cla_line);
	}

    string word_check(string input) // checks what type of word it falls under. (only for classification *word*)
    {
        if (input[0] == '"')
        {
            return("string");


        }
        if ((int)input[0] >= 48 && (int)input[0] <= 57)
        {
            return("number");
        }
        else
        {
            return("variable");
        }

    }

    string character_classification(string characters)   // for individual token validation.
    {
        vector <string> alphabet;
        for (char c = 'a'; c <= 'z'; ++c) {
            alphabet.push_back(string(1, c));
        }

        // Adding uppercase letters
        for (char c = 'A'; c <= 'Z'; ++c) {
            alphabet.push_back(string(1, c));
        }    //stores all lowercase letters.
        vector<string> uppercase_alphabet;
        vector<string> number{"0","1","2","3","4","5","6","7","8","9"};
        vector<string>special_character{
             "+", "-", "*", "/", "%", "**", "//",
        "=", "+=", "-=", "*=", "/=", "%=", "//=", "**=", "&=", "|=", "^=", ">>=", "<<=",
        "==", "!=", ">", "<", ">=", "<=",
        "&", "|", "^", "~", "<<", ">>", "&", "$"
        };
        vector <string> seperator{ "(", ")", "[", "]", "{", "}", ",", ":", ".", ";", "@" };


        string underscore = "_";

        char letter = 'a';
        while (letter <= 'z')
        {
            string alph(letter, 1);
            alphabet.push_back(alph);
            letter++;
        }
        letter = 'A';
        while (letter <= 'Z') // stores all the upperase letters.    
        {
            string alph(letter, 1);
            uppercase_alphabet.push_back(alph);
            letter++;
        }

        for (int x = 0; x <alphabet.size();x++) //checks if the character is a letter or not.
        {
            if (characters == alphabet.at(x))
                return("letter");
            
        }
        for (int x = 0; x < number.size(); x++)
        {
            if (characters == number.at(x))
                return("number");
        }
        for (int x = 0; x < special_character.size();x++)
        {
            if (characters == special_character.at(x))
            {
                return("special_character");
            }
        }
        for (int x = 0;x < seperator.size();x++)
        {
            if (characters == seperator.at(x))
            {
                return("seperator");
            }
        }
        if (characters == underscore)
        {
            return(underscore);
        }



    }

};