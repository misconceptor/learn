#include <vector>
#include <tuple>


std::vector<std::tuple<int,int,int>> pointsInCircle(
    double r, const std::vector<std::tuple<int,int,int>> &t)
{
    std::vector<std::tuple<int,int,int>> ans;
    for(auto i : t){
        int color = std::get<0>(i);
        int x = std::get<1>(i);
        int y = std::get<2>(i);
        if((x*x) + (y*y) <= (r*r)){
            ans.push_back(std::make_tuple(color,x,y));
        }
    }
    return ans;
}