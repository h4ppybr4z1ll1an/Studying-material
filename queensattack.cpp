//Solution to the problem at https://www.hackerrank.com/challenges/queens-attack-2/problem


int queensAttack(long long int n, long long int k, long long int r_q, long long int c_q, vector<vector<long long int>> obstacles) {

    //n == board side
    //k == number of obstacles
    //r_q == queen's row
    //c_q == queen's column
    //obstacles = vector containing vectors???? (I'd rather have pairs...but...) with obstacles coordinates

    if (n <= 1)
        return 0;
   
    //First the board from now on will be seen as a matrix with sequential elements.
    //Then we find which element corresponds the fartest for each given direction (north, south, west, east, northwest, \
    //southeast, northeast, southwest).
    //To find it for the elements that are in diagonal (nw, se, ne, sw) we look for which coordinate (row or column) is nearer 
    //from 1 on the nw and ne directions and which one is nearer n on the se and sw directions and find the difference between the queens
    //corresponding coordinate
    //The result of this, it summed or subtracted accordingly from the queens coordinates and then we calculate which element corresponds
    //to given position.
    //Finding N, S, W and E is pretty straightfoward. Just read the code.
    
    long long int queen = (r_q - 1) * n + c_q;

    long long int n_max = c_q;
    long long int s_max = (n - 1) * n + c_q;

    long long int w_max = n * (r_q - 1) + 1;
    long long int e_max = n * r_q;

    const long long int nw_dif = c_q - 1 < r_q - 1 ? c_q - 1 : r_q - 1;
    long long int nw_max = (r_q - nw_dif - 1) * n + c_q - nw_dif;

    const long long int se_dif = n - c_q < n - r_q ? n - c_q : n - r_q;
    long long int se_max = (r_q + se_dif - 1) * n + c_q + se_dif;

    const long long int ne_dif = n - c_q < r_q - 1 ? n - c_q : r_q - 1;
    long long int ne_max = (r_q - ne_dif - 1) * n + c_q + ne_dif;

    const long long int sw_dif = c_q - 1 < n - r_q ? c_q - 1 : n - r_q;
    long long int sw_max = (r_q + sw_dif - 1) * n + c_q - sw_dif;
    
    
    //Used to calculate 
    bool has_w(0), has_e(0),
         has_n(0), has_s(0), 
         has_ne(0),has_sw(0),
         has_nw(0),has_se(0);

    for (vector<long long int>& obs : obstacles) {
        long long int piece = (obs.at(0) - 1) * n + obs.at(1);
        
        //Finding obstacles between W and E is pretty straightfoward
        if (piece >= w_max && piece < queen) {
            w_max = piece;
            has_w = 1;
            continue;
        }

        if (piece <= e_max && piece > queen) {
            e_max = piece;
            has_e = 1;
            continue;
        }
        
        //Each direction is a set that starts with an element(n_max, nw_max, ne_max) and ends with other(s_max, se_max, sw_max).
        //If you look on a board for the aligment on these directions, you will see a pattern on the elements, that corresponds to a
        //difference of n for each element on the set {n_max, ... , s_max}, n+1 for each element on the set {nw_max, ..., se_max} and 
        //n-1 for each element on the set {ne_max, ..., sw_max}. 
        
        //So, if an element is within the range of given set and the element and queen absolute difference % n, n+1 or n-1 accordingly 
        //is equal 0, finding which element is the (n_max, nw_max, ne_max and their corresponding directions) maximum the queen can move
        //to becomes pretty easy.
        
        //There are some bools holding if an obstacle is found as it's not possible to move to a given coordinate if there is an obstacle,
        //Thus reducing by one the quantity of moves
        
        long long int pc_dif = piece > queen ? piece - queen : queen - piece;
        if (pc_dif % n == 0) {
            if (piece >= n_max && piece < queen) {
                n_max = piece;
                has_n = 1;
                continue;
            }
            else if (piece <= s_max && piece > queen) {
                s_max = piece;
                has_s = 1;
                continue;
            }
        }

        if (pc_dif % (n + 1) == 0) {
            if (piece >= nw_max && piece < queen) {
                nw_max = piece;
                has_nw = 1;
                continue;
            }
            else if (piece <= se_max && piece > queen) {
                se_max = piece;
                has_se = 1;
                continue;
            }
        }

        if (pc_dif % (n - 1) == 0) {
            if (piece >= ne_max && piece < queen) {
                ne_max = piece;
                has_ne = 1;
                continue;
            }
            else if (piece <= sw_max && piece > queen) {
                sw_max = piece;
                has_sw = 1;
                continue;
            }
        }

    }

    long long int moves = 0;
    moves += (queen - w_max - has_w) + (e_max - queen - has_e);
    
    //Calculating how many moves are possible is pretty straightfoward too!!
    //It's the absolute difference between the element corresponding to the maximum possible coordinate on
    //given direction and the queen divided by the absolute difference of an element x and x+1 minus 1
    //if there is an obstacle on the maximum possible coordinate for given direction.
    
    moves += (queen - n_max) / n - has_n + (s_max - queen) / n - has_s;
    moves += (queen - nw_max) / (n + 1) - has_nw + (se_max - queen) / (n + 1) - has_se;
    moves += (queen - ne_max) / (n - 1) - has_ne + (sw_max - queen) / (n - 1) - has_sw;
    
    //Sorry for english mistakes, portuguese is my mother tongue.
    //Some variables only exist for the sake of readability or for some calculations to not happen twice, although I suspect
    //the compiler would optimize anyways.
    //With little modification it's possible to find which coordinates the queen can go, thus being useful for a chess game
    //where a visual clue of possible moves might be useful.
    
    

    return moves;
}
