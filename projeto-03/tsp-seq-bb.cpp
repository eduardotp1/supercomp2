#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <random>
#include <limits>
#include <utility>
#include <iomanip>




double dist(std::pair<double,double> &p1, std::pair<double,double> &p2){
    return sqrt(pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2));
}

double path_dist(std::vector<int> seq, std::vector<std::pair<double,double>>  points){
    double d = dist(points[seq[seq.size()-1]],points[seq[0]]);
    for(int i=0;i<seq.size()-1;i++){
        d += dist(points[seq[i]],points[seq[i+1]]);
    }
    return d;
}

double backtrack(std::vector<std::pair<double,double>> points, int idx,
double curr_cost,std::vector<int> &curr_sol,double best_cost,
std::vector<int> &best_seq, std::vector<bool> &usado){
    if(curr_cost>best_cost){
        return best_cost;
    }
    if(idx==points.size()){

        curr_cost += dist(points[curr_sol[0]],points[curr_sol[curr_sol.size()-1]]);
        if(curr_cost < best_cost){
            best_seq.assign(curr_sol.begin(),curr_sol.end());
            best_cost=curr_cost;
            // std::cout << "Best: " << best_cost<< "\n";
        }
        return best_cost;
    }   

    for(int i=0;i<points.size();i++){
        if(!usado[i]){
            usado[i]=true;
            curr_sol[idx] = i;

            double new_cost = curr_cost + dist(points[curr_sol[idx-1]],points[curr_sol[idx]]);
            best_cost = backtrack(points, idx+1, new_cost, curr_sol, best_cost,best_seq,usado);

            usado[i]= false;
            curr_sol[idx]=-1;
        }
    }
    return best_cost;
}


int main(){

    auto start_time = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(5);
    std::vector<std::pair<double,double>> points;
    std::vector<bool> usado;
    std::vector<int> curr_sol;
    std::vector<int> best_sol;
    int N;
    double x,y;
    double a = std::numeric_limits<double>::max();
    std::cin >> N;
    
    for(int i=0;i<N;i++){
        std::cin >> x;
        std::cin >> y;

        points.push_back(std::make_pair(x,y));

        usado.push_back(false);
        curr_sol.push_back(-1);
        best_sol.push_back(-1);
    }

    curr_sol[0]=0;
    usado[0]=true;

    backtrack(points,1,0,curr_sol,a,best_sol,usado);

    std::cout << path_dist(best_sol,points) << " 1" << "\n";

    for(int i=0;i<best_sol.size();i++){
        std::cout<< best_sol[i] << " " ;
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "\n" << "Demorou: "<< runtime.count() << " ms";
}