/*
C++
In this problem we check the closest obstacle to the queen in all the eight directions, 
then we calculate the distance queen can travel and return the sum.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,o,rq,cq;
    cin>>n>>o;
    int arr[n][n],row[o],col[o];
    cin>>rq>>cq;
    int right=n-cq;
    int left=cq-1;
    int up=n-rq;
    int down=rq-1;
    int right_up=min(right,up);
    int left_up=min(left,up);
    int right_down=min(right,down);
    int left_down=min(left,down);
    int ro,co;
    for(int i=0;i<o;i++){
        cin>>ro>>co;
        if(ro==rq && co<cq){
            if(cq-co-1<left){
            left=cq-co-1;}
        }
        else if(ro==rq && co>cq){
            if(co-cq-1<right){
            right=co-cq-1;
            }
        }
        else if(co==cq && ro<rq){
            if(down>rq-ro-1){
                down=rq-ro-1;
            }
        }
         else if(co==cq && ro>rq){
            if(up>ro-rq-1){
                up=ro-rq-1;
            }
        }
        else if(ro>rq && co>cq){
            if((ro-rq)==(co-cq)){
                if(right_up>ro-rq-1){
                    right_up=ro-rq-1;
                }
            }
        }
        else if(ro>rq && co<cq){
            if((ro-rq)==(cq-co)){
                if(left_up>ro-rq-1){
                    left_up=ro-rq-1;
                }
            }
        }
        else if(ro<rq && co<cq){
            if((rq-ro)==(cq-co)){
                if(left_down>cq-co-1){
                    left_down=cq-co-1;
                }
            }
        }
        else if(rq>ro && co>cq){
            if((rq-ro)==(co-cq)){
                if(right_down>co-cq-1){
                    right_down=co-cq-1;
                }
            }
        }
    }
    int sum=left+right+up+down+right_up+right_down+left_up+left_down;
    cout<<sum;
}