#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

class alloprations{
    public:
        vector<vector<int>> initialize(int N){
         vector<vector<int>> planegen;
            for(int i=0;i<N;i++)
                {
                vector<int> temp;
            for(int j=0;j<N;j++)
            { 
                temp.push_back(rand() % 2);
            }
            planegen.push_back(temp);
        }
            return planegen;
        }
};

//Create a method, given a coordinate, that counts the number of neighbours at that coordinate.
int countNeigh(vector<vector<int>>& plane , int x,int y){
    int count;
    int N = plane[0].size();
    
    if((x == 0 || x == N-1) && ( y == 0 || y == N-1))
        count = 3;
    else if((x > 0 && x < N-1) && (y == 0 || y == N-1))
        count = 5;
    else if((y > 0 && y < N-1) && (x == 0 || x == N-1))
        count = 5;
    else if( x > N-1 || y > N-1)
        count = 0;
    else 
        count = 8;
    
    return count;
}

//Create a method that displays the grid of cells, this can be either on the console or any other means you think possible.
void displayGrid(vector<vector<int>>& plane){
    int N = plane[0].size();
    cout << endl;
    cout << "new Grid is " <<endl;
    cout << endl;
    for(int i = 0; i < N;i++){
        for(int j =0; j < N;j++){
            cout << plane[i][j] << " " ;
        }
        cout << endl;
    }

}
//Add a method that implements the rules of Conways game of life to produce the games next iteration from the current
vector<vector<int>> nextIteration(vector<vector<int>>& plane,bool setbit) {
        int neighb[3] = {0,1,-1};
        int row = plane.size();
        int col = plane[0].size();       
 //iterate thro grid cell by cell
        for(int i = 0; i < row;i++){
            for(int  j =0;j< col;j++){
                int live_neighb =0;
                
                //for each cell count the number of the live neighbors
                for(int  k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        
                        if(!(neighb[k] == 0 && neighb[l] == 0))
                        {
                            int r = (i + neighb[k]);
                            int c = (j + neighb[l]);
                            //check if value of r and c exceeds matrix size
                            if(setbit == true){
                            if(r > row  )
                                r = 0;
                            else if (r <  -1)
                                r = row-1;
                            if(c > col  )
                                c = 0;
                            else if (c <  -1)
                                c = col-1;
                            }
                            
                            if((r < row && r >= 0) &&(c < col && c >=0) && (abs(plane[r][c]) == 1)){
                                live_neighb +=1;
                                
                            }
                               
                               }
                    }
                }
                               //rule 1 and 3
                               if((plane[i][j] == 1) &&(live_neighb <2  || live_neighb >3) ){
                                    plane[i][j] = -1;      
                               }
                               //rule 4
                               if((plane[i][j] == 0) && (live_neighb == 3)){
                                   plane[i][j] = 2;
                               }      
            }
        }
                               //update grid with binary values
                               
        for(int i = 0; i < row;i++){
            for(int  j =0;j< col;j++){
                if(plane[i][j] > 0){
                    plane[i][j] = 1;
                }else{
                    plane[i][j] = 0;
                }
            }
        }
        displayGrid(plane);
        return plane;
    }
    

void exitgame(){
    cout << "Thanks for your time !!" << endl;
}

int main(){

    int N;
    alloprations obj;
    int count,x,y;
    vector<vector<int>> GamePlane;
    cout << "Enter number of grids !" << endl;
    cin >> N;
    GamePlane = obj.initialize(N);
    displayGrid(GamePlane);
    int opt;
    

    do
	{
		do
		{
			cout << " please enter the 0 to count the number of neighbours at given coordinate" <<endl;
            cout << " please enter the 1 to produce the games next iteration from the current using rules" <<endl;
            cout << " please enter the 2 to make the grid of cells toroidal" <<endl;
            cout << " please enter the 3 to display cureent plane " <<endl;
            cout << " please enter the 4 to exit game" << endl;
            cout << " Please enter your choice between 0 and 4: ";
            cin >> opt;
	
		}while(opt > 4 || opt < 0);

        if(opt == 0){
        cout<< "enter the position of cell to find neighbour count in range 0 to " << N-1 <<endl;
        cin >> x >> y;
        count = countNeigh(GamePlane,x,y);
        cout<<"count is "<<count <<endl;
    }else if (opt == 1){
        GamePlane = nextIteration(GamePlane,false);
    }else if (opt == 2){
        GamePlane = nextIteration(GamePlane,true);
    }else if (opt == 3){
       displayGrid(GamePlane);
    } else if (opt == 4){
        exitgame();
    }
    }while(opt != 4);

    return 0;
     
}