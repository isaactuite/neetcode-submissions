class Solution {
public:
    string encode(const vector<string>& strs) {
        string encoded;

        for (const string& str : strs) {
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(const string& encoded) {
        vector<string> result;
        size_t i = 0;

        while (i < encoded.size()) {
            // Find the separator after the length.
            size_t separator = encoded.find('#', i);

            // Parse the length.
            size_t length = stoul(encoded.substr(i, separator - i));

            // Move past "length#".
            i = separator + 1;

            // Read exactly `length` characters.
            result.push_back(encoded.substr(i, length));

            // Move to the next encoded string.
            i += length;
        }

        return result;
    }
};