#include "snowman.hpp"
#include <array>
#include <string.h>
using namespace std;

const int legal_length = 8;
const int max_val = 4;
const int min_val = 1;
const int UP = 1;
const int _hat = 0;
const int _nose = 1;
const int _leye = 2;
const int _reye = 3;
const int _larm = 4;
const int _rarm = 5;
const int _torso = 6;
const int _base = 7;
const long int Lrange = 10000000;
const long int Urange = 99999999;


namespace presets
{

    const array<string, 4> Hat = {
        "      \n _===_",
        "  ___ \n .....",
        "   _  \n  /_\\ ",
        "  ___ \n (_*_)",
    };

    const array<string, 4> Nose = {
        ",",
        ".",
        "_",
        " ",
    };
    const array<string, 4> Eye = {
        ".",
        "o",
        "O",
        "-",
    };
    const array<string, 4> LeftArms = {
        "<",
        "",
        "/",
        " ",
    };
    const array<string, 4> LeftArmsup = {
        " ",
        "\\",
        " ",
        " ",
    };

    const array<string, 4> RightArms = {
        ">",
        " ",
        "\\",
        " ",
    };
    const array<string, 4> RightArmsup = {
        " ",
        "/",
        " ",
        " ",
    };

    const array<string, 4> Torso = {
        " : ",
        "] [",
        "> <",
        "   ",
    };
    const array<string, 4> Base = {
        " : ",
        "\" \"",
        "___",
        "   ",
    };

}

namespace ariel
{

    string snowman(int num)
    {

        if (num>Urange||num<Lrange){
            throw std::out_of_range{"invalid input"};
        }

        int digit = 0;
        const int mod = 10;
        array<int ,legal_length> limbs = {0};
        for (int i = 0; i < legal_length; i++)
        {
            digit = (num % mod);
            //catch the inlegal 8 digit numbers.
            if (digit < min_val || digit > max_val){
                throw std::out_of_range{"values must be 1<=n<=4"};
            }
            limbs.at(legal_length-i-1) = digit - 1;
            num = num / mod;
        }
    
        string olaf;

        olaf.append(presets::Hat.at(limbs.at(_hat)));
        olaf.append("\n");

        olaf.append(presets::LeftArmsup.at(limbs.at(_larm)));
        olaf.append("(");
        olaf.append(presets::Eye.at(limbs.at(_leye)));
        olaf.append(presets::Nose.at(limbs.at(_nose)));
        olaf.append(presets::Eye.at(limbs.at(_reye)));
        olaf.append(")");
      
        olaf.append(presets::RightArmsup.at(limbs.at(_rarm)));
        olaf.append("\n");

        olaf.append(presets::LeftArms.at(limbs.at(_larm)));
        olaf.append("(");
        olaf.append(presets::Torso.at(limbs.at(_torso)));
        olaf.append(")");
       
        olaf.append(presets::RightArms.at(limbs.at(_rarm)));

        olaf.append("\n");

        olaf.append(" (");
        olaf.append(presets::Base.at(limbs.at(_base)));
        olaf.append(")");

        return olaf;
    }

}
