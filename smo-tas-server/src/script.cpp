#include "tas.h"
#include <cmath>
#include <common.h>
#include <deque>
#include <iostream>
#include <iterator>
#include <memory>
#include <script.h>
#include <sstream>
#include <stdexcept>
#include <string>

fl::TasScript fl::script::fromText(std::stringstream& file)
{
    std::string line;
    TasScript script;

    size_t curLine = 0;
    while (std::getline(file, line))
    {
        if (line == "") continue;

        TasFrame frame;
        std::deque<std::string> tokens = fl::split(line, ' ');
        if (tokens.size() != 4)
        {
            std::string err("Invalid Script: line ");
            err.append(std::to_string(curLine));
            err.append(" has ");
            err.append(std::to_string(tokens.size()));
            err.append(" tokens.");
            throw std::invalid_argument(err);
        }

        size_t lineNum = std::stoi(tokens[0]);

        {
            std::deque<std::string> lStickTokens = fl::split(tokens[2], ';');
            if (lStickTokens.size() != 2)
            {
                std::string err("Invalid Script: line ");
                err.append(std::to_string(curLine));
                err.append(" has left stick ; ");
                err.append(std::to_string(lStickTokens.size()));
                err.append(" tokens.");
                throw std::invalid_argument(err);
            }
            frame.leftStick.x = std::stoi(lStickTokens[0]) / 32767.0f;
            frame.leftStick.y = std::stoi(lStickTokens[1]) / 32767.0f;

            std::deque<std::string> rStickTokens = fl::split(tokens[3], ';');
            if (rStickTokens.size() != 2)
            {
                std::string err("Invalid Script: line ");
                err.append(std::to_string(curLine));
                err.append(" has right stick ; ");
                err.append(std::to_string(rStickTokens.size()));
                err.append(" tokens.");
                throw std::invalid_argument(err);
            }
            frame.rightStick.x = std::stoi(rStickTokens[0]) / 32767.0f;
            frame.rightStick.y = std::stoi(rStickTokens[1]) / 32767.0f;
        }

        if (tokens[1] != "NONE")
        {
            std::deque<std::string> buttonTokens = fl::split(tokens[1], ';');
            for (const std::string& button : buttonTokens)
            {
                if (button == "KEY_A") frame.A = true;
                else if (button == "KEY_B") frame.B = true;
                else if (button == "KEY_X") frame.X = true;
                else if (button == "KEY_Y") frame.Y = true;
                else if (button == "KEY_ZR") frame.ZR = true;
                else if (button == "KEY_ZL") frame.ZL = true;
                else if (button == "KEY_R") frame.R = true;
                else if (button == "KEY_L") frame.L = true;
                else if (button == "KEY_PLUS") frame.plus = true;
                else if (button == "KEY_MINUS") frame.minus = true;
                else if (button == "KEY_DLEFT") frame.dLeft = true;
                else if (button == "KEY_DRIGHT") frame.dRight = true;
                else if (button == "KEY_DUP") frame.dUp = true;
                else if (button == "KEY_DDOWN") frame.dDown = true;
                else if (button == "KEY_LSTICK") frame.pressLeftStick = true;
                else if (button == "KEY_RSTICK") frame.pressRightStick = true;
            }
        }

        script.frames.push_back(frame);

        if (lineNum != curLine)
        {
            size_t add = abs((s32) curLine - (s32) lineNum);
            for (int i = 0; i < add; i++) script.frames.push_back(TasFrame());
            curLine += add;
        }

        curLine++;
    }

    return script;
}

fl::TasScript fl::script::fromText(std::ifstream& file)
{
    std::stringstream i;
    i << file.rdbuf();
    return fl::script::fromText(i);
}

fl::TasScript fl::script::fromText(const std::string &file)
{
    std::ifstream str(file);
    return fl::script::fromText(str);
}

#define ADD_KEY(KEY_STRING, MEMBER_NAME) if (frame.MEMBER_NAME) {if (!firstKey) ss << ";"; else firstKey = false; ss << KEY_STRING; any = true;}

std::string fl::script::toText(const TasScript& script)
{
    std::stringstream ss;
    
    size_t curLine = 0;
    for (const TasFrame& frame : script.frames)
    {
        ss << curLine << " ";
        bool firstKey = true;
        bool any = false;
        ADD_KEY("KEY_A", A);
        ADD_KEY("KEY_B", B);
        ADD_KEY("KEY_X", X);
        ADD_KEY("KEY_Y", Y);
        ADD_KEY("KEY_ZR", ZR);
        ADD_KEY("KEY_ZL", ZL);
        ADD_KEY("KEY_R", R);
        ADD_KEY("KEY_L", L);
        ADD_KEY("KEY_PLUS", plus);
        ADD_KEY("KEY_MINUS", minus);
        ADD_KEY("KEY_DLEFT", dLeft);
        ADD_KEY("KEY_DRIGHT", dRight);
        ADD_KEY("KEY_DUP", dUp);
        ADD_KEY("KEY_DDOWN", dDown);
        ADD_KEY("KEY_LSTICK", pressLeftStick);
        ADD_KEY("KEY_RSTICK", pressRightStick);

        if (!any) ss << "NONE";

        s16 lX = frame.leftStick.x * 32767;
        s16 lY = frame.leftStick.y * 32767;

        s16 rX = frame.rightStick.x * 32767;
        s16 rY = frame.rightStick.y * 32767;

        ss << " " << lX << ";" << lY << " " << rX << ";" << rY << "\n";

        curLine++;
    }

    return ss.str();
}

#undef ADD_KEY