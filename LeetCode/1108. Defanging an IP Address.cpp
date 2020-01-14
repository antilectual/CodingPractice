//1108. Defanging an IP Address
class Solution {
public:
    string defangIPaddr(string address) {
        string p("[.]");
        stringstream defangMe(address);
        int first, second, third, fourth;
        char period;
        defangMe >> first >> period >> second >> period  >> third >> period  >> fourth;
        return to_string(first) + p + to_string(second) + p + to_string(third) + p + to_string(fourth);
    }
};