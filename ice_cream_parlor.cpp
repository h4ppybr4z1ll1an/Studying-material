void whatFlavors(vector<int> cost, int money) {
    // Prices are not unique, so we store which indices have the same price on a vector
    std::unordered_map<int, std::vector<size_t>> flavor_indices;

    for(size_t i = 0; i < cost.size(); ++i) {
        flavor_indices[cost[i]].push_back(i+1);
    }

    for(auto& pair : flavor_indices) {
        // No money left after buying one flavor
        if(pair.first >= money)
            continue;

        auto it = flavor_indices.find(money - pair.first);

        
        if(it != flavor_indices.end()) {
            // We found a candidate that fits whatever we have left!!
            // Presuming that it's not the same index, that is, 2 different flavors
            // have been choosen, we already assign them.
            size_t a = pair.second[0];
            size_t b = (*it).second[0];

            if(pair.first == (*it).first) {
                // The same flavor twice satisfy the spending, though we can't buy it twice
                if(pair.second.size() == 1){
                    continue;
                }
                else {
                    // We have two different flavors with the same price, yay!
                    a = pair.second[0];
                    b = pair.second[1];
                }
            }    
            
            // Self explanatory
            if(b < a) 
                std::swap(a,b);
    
            std::cout << a << " " << b << "\n";
            break;
        }
    }       
}
