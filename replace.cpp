#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

/**
 * Main function to read function call and function body from user,
 * then replace specific placeholders in a file with these inputs.
 */
int main() {
    string function_call;
    string code;
    string temp;

    // Read function call from user
    cout << "Enter the function call: ";
    getline(cin, function_call);

    // Read function body from user
    cout << "Enter the complete function body with a //base_condition as a comment right above a base condition and last line as \"STOP\" to stop the input: ";
    getline(cin, temp);
    while (temp != "STOP") {
        code += temp + "\n";
        getline(cin, temp);
    }

    for(int i=0;i<code.size();i++){
        if(code[i]=='{'){
            code.insert(i+1,"\n");
            code.insert(i+2,"    argument_array.push_back(n);\n");
            break;
        }
    }

    // File name to be processed
    string filename = "code.cpp";
    ifstream file_in(filename);

    // Read the entire file content into a string
    stringstream buffer;
    buffer << file_in.rdbuf();
    string content = buffer.str();
    file_in.close();

    // Replace "#code_here" with the function body
    string search_str = "//#code_here";
    string replace_str = code;
    size_t pos = content.find(search_str);
    while (pos != string::npos) {
        content.replace(pos, search_str.length(), replace_str);
        pos = content.find(search_str, pos + replace_str.length());
    }

    // Replace "#function_call_here" with the function call
    search_str = "//#function_call_here";
    replace_str = function_call;
    pos = content.find(search_str);
    while (pos != string::npos) {
        content.replace(pos, search_str.length(), replace_str);
        pos = content.find(search_str, pos + replace_str.length());
    }


    search_str = "//base_condition";
    replace_str = "argument_array.push_back(-1);\nargument_array.push_back(-1);\n";
    pos = content.find(search_str);
    while (pos != string::npos) {
        content.replace(pos, search_str.length(), replace_str);
        pos = content.find(search_str, pos + replace_str.length());
    }

    // Write the modified content back to the file
    ofstream file_out(filename);
    file_out << content;
    file_out.close();

    // Call the start function of code.cpp
    system("g++ code.cpp -o code && code");

     ofstream fout("code.cpp");
    fout<< "#include<iostream>\n#include \"recurtion.cpp\"\nusing namespace std;\n\n//#code_here\n\nint main() {\n    //#function_call_here;\n   TreeNode* root = buildTree(argument_array);\n   printNode(root);\nreturn 0;\n}\n";
    fout.close();

    return 0;
}