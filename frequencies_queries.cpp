//My (quick and dirty) solution to the challenge found at https://www.hackerrank.com/challenges/frequency-queries/problem


// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    std::unordered_map<int, int> number_frequency;
    std::unordered_map<int, std::unordered_set<int>> frequency_number;
    std::vector<int> result;
    
    for(auto& query : queries) {
        auto op = query[0];
        auto data = query[1];

        switch(op) {
            case 1: {
                auto& frequency = number_frequency[data];
                auto it = frequency_number[frequency].find(data);
                if(it != frequency_number[frequency].end()) 
                    frequency_number[frequency].erase(it);
                
                ++frequency;
                frequency_number[frequency].insert(data);
                break;
            }          
            case 2: {
                auto& frequency = number_frequency[data];
                if(frequency != 0) {
                    auto it = frequency_number[frequency].find(data);
                    frequency_number[frequency].erase(it);
                    --frequency;
                    frequency_number[frequency].insert(data);
                }
                break;
            }
            case 3:
                if(frequency_number[data].size() > 0)
                    result.push_back(1);
                else 
                    result.push_back(0);

                break;
            default:
                break;

        }
    }

    return result;
}
