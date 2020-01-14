#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

// Data types

struct nq
{
    int n;
    int q;
};

struct attribute
{
    string name;
    string value;
};

struct tagQuery
{
    string attribute;
    vector<string> tags;
};

struct tag
{
    string name;
    bool isClosing = false;
    vector<attribute> attributes;
};

// Function Prototypes
void runQuery(vector<tag*> tags, tagQuery * query);


// Functions
string trimLastCharFromStr(string trimMe)
{
    trimMe.erase(trimMe.length() - 1);
    return trimMe;
}

/*    Function: ParseTag(string, tag*)

    Description: Converts the input line into a tag object 
    with appropriate name, attributes, and whether or not it is a closing tag.
*/
tag * parseTag(string tagInput, tag *tagRef)
{
    stringstream tagInputSS(tagInput);
    char tempChar, tempQuotes;
    string attributeName, attributeValue, tempEquals;
    attribute tempAttribute;
    tagInputSS >> tempChar;
    // Test for and get closing tag
    if(tagInputSS.peek() == '/')
    {
        string tagName;
        tagRef->isClosing = true;
        tagInputSS >> tempChar;
        tagInputSS >> tagName;
        // trim trailing bracket (>)
        tagName = trimLastCharFromStr(tagName);
        tagRef->name = tagName;
        return tagRef;
    }
    tagInputSS >> tagRef->name;
    // Test for tag having no attributes
    if((tagRef->name)[tagRef->name.length() - 1] == '>')
    {
        tagRef->name = trimLastCharFromStr(tagRef->name);
        return tagRef;
    }
    // Get the attributes for a tag
    while(tagInputSS.peek() == ' ' && !tagInputSS.eof())
    {
        tagInputSS >> attributeName;
        tempAttribute.name = attributeName;
        tagInputSS >> tempEquals >> tempQuotes >> attributeValue;
        attributeValue = trimLastCharFromStr(attributeValue);
        tempAttribute.value = attributeValue;
        // if > was trimmed off end instead of "
        if(attributeValue[attributeValue.length() -1] == '"')
        {
            attributeValue = trimLastCharFromStr(attributeValue);
            tempAttribute.value = attributeValue;
            tagRef->attributes.push_back(tempAttribute);
            return tagRef;
        }
        else
        {
            tagRef->attributes.push_back(tempAttribute);
        }
    }
    return tagRef;
}

/*    Function: ParseQuery(string, tagQuery*)

    Description: Converts the input line into a tagQuery object 
    with appropriate search tags and attribute query.
*/
tagQuery * parseQuery(string tagInput, tagQuery *tagQueryRef)
{
    stringstream tagInputSS(tagInput);
    string tempTag;
    while(!tagInputSS.eof())
    {
        getline(tagInputSS, tempTag, '.');
        tagQueryRef->tags.push_back(tempTag);
    }
    // split final tag its attribute
    stringstream tagAndAttrib(tagQueryRef->tags.back());
    tagQueryRef->tags.pop_back();
    while(!tagAndAttrib.eof())
    {
        getline(tagAndAttrib, tempTag, '~');
        tagQueryRef->tags.push_back(tempTag);
    }
    tagQueryRef->attribute = tagQueryRef->tags.back();
    tagQueryRef->tags.pop_back();
    return tagQueryRef;
}

void runQueries(vector<tag*> tags, vector<tagQuery*> queries)
{

    // iterate through all queries
    for(int i = 0; i < queries.size() ; i++)
    {
        runQuery(tags, queries[i]);
    }
}

void runQuery(vector<tag*> tags, tagQuery * query)
{
    int queryIndex = 0;
    vector<string> tagsStack;
    // iterate through all tags
    for(int j = 0; j < tags.size(); j++)
    {
        if(tags[j]->isClosing == false)
        {
            tagsStack.push_back(tags[j]->name);
        }
        // test if tag is equal to the current query tag
        if (tags[j]->name == query->tags[queryIndex] && tags[j]->isClosing == false && tagsStack.size() == queryIndex + 1)
        {
            queryIndex++;
            // Found final tag
            if(queryIndex == query->tags.size())
            {
                //iterate through attributes on matching tag
                for(int k = 0; k < tags[j]->attributes.size(); k++)
                {
                    // found attribute!
                    if(tags[j]->attributes[k].name == query->attribute)
                    {
                        cout << tags[j]->attributes[k].value << endl;
                        return;
                    }
                }
            }
            
        }
        else if(!tagsStack.empty() && tags[j]->isClosing == true && tagsStack.back() == query->tags[queryIndex-1])
        {
            queryIndex--;
            tagsStack.pop_back();
        }
        else if (!tagsStack.empty() && tagsStack.back() == tags[j]->name && tags[j]->isClosing == true)
        {
            tagsStack.pop_back();
        }
    }
    cout << "Not Found!" << endl;
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q;
    string nqLineStr;
    vector<string> tagInputs;
    vector<string> queryInputs;
    vector<tag*> tags;
    vector<tagQuery*> queries;
    getline(cin, nqLineStr);
    stringstream nqLine(nqLineStr);
    nqLine >> n >> q;
    // get tags (N)
    for(int i = 0; i < n; i++)
    {
        string tempTagInput;
        tag *tempTag = new tag;
        getline(cin, tempTagInput);
        tempTag = parseTag(tempTagInput, tempTag);
        tags.push_back(tempTag);
    }
    // get queries (Q)
    for(int i = 0; i < q; i++)
    {
        string tempQueryInput;
        tagQuery *tempTagQuery = new tagQuery;
        getline(cin, tempQueryInput);
        tempTagQuery = parseQuery(tempQueryInput, tempTagQuery);
        queries.push_back(tempTagQuery);
    }
   
    runQueries(tags, queries);
    return 0;
}

