
class Solution {
public:

    string encode(vector<string>& strs) 
    {
        // declare final string
        string s;
        // for each string in input vector
        for (size_t i = 0; i < strs.size(); ++i)
        {
            // take length of string as type size_t (unsigned int for storing counts)
            size_t len = strs[i].length();
            // string to store length of encoded string in bytes
            string tmp;
            // for each byte of the strings length
            for (size_t i = 0, mask = 0xff; i < sizeof(size_t); ++i, mask <<= 8)
            {
                // masks one byte of len and pushes back to tmp
                tmp.push_back(len& mask);
            }
            // reverse string to convert from little endian to big endian where first byte is more significant
            reverse(tmp.begin(), tmp.end());
            // append bytes representing length of string followed by original string itself
            s.append(tmp);
            s.append(strs[i]);
        }

        return s;
    }

    vector<string> decode(string s) {
        // vector to store decoded strings
        vector<string> strs;
		// position in encoded string
		size_t pos = 0;

        // while there are enough bytes left to read in string
        while (pos + sizeof(size_t) <= s.length())
        {
            // declare length of the next string to 0
			size_t len = 0;
            // loop once for each byte of length prefix to calculate length of next original string
            for (size_t i = 0; i <sizeof(size_t); ++i)
            {
                // shift current length 8 bits to left to make room for next byte 
				len <<= 8;
                // read the next byte from the encoded as a number (0-255), and add it to len  
                // increment pos to move to the next byte  
				len += static_cast<unsigned char>(s[pos++]);
			}

            // extract next 'len' characters from the encoded string and add them to the vector of strings  
			strs.push_back(s.substr(pos, len));
            // move pos forward past string we just extracted, ready for next iteration
			pos += len;
        }

        // return full vector of decoded strings
		return strs;
    }
};
