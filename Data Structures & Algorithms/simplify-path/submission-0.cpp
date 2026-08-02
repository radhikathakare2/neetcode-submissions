class Solution {
public:
    string simplifyPath(string path) {

        vector<string> dirs;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (curr == "" || curr == ".") {
                    // Ignore
                }
                else if (curr == "..") {
                    if (!dirs.empty())
                        dirs.pop_back();
                }
                else {
                    dirs.push_back(curr);
                }

                curr = "";
            }
            else {
                curr += path[i];
            }
        }

        if (dirs.empty())
            return "/";

        string ans = "";

        for (string dir : dirs)
            ans += "/" + dir;

        return ans;
    }
};