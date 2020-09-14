/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>

using namespace std;

int main(){
    register int n, m, i, j;
    int key, num;
    vector<int> v;

    scanf("%d", &n);
    while (n--){
        scanf("%d", &m);

        if (m == 1){
            /**
             * If only 1 input then no need to process
             * For 1 input the distance is always Zero
             */
            scanf("%*d");
            printf("0\n");
        }

        else{
            /**
             * Input an a value and push it to vector
             */
            v.clear();
            for (i = 0; i < m; ++i){
                scanf("%d", &num);
                v.push_back(num);
            }

            /**
             * sort for median
             */
            nth_element(v.begin(), v.begin() + v.size()/2, v.end());

            /**
             * Get the value of median
             */
            key = v[v.size()/2];

            /**
             * Get distance of every value from median
             */
            int dist = 0;
            for (j = 0; j < i; ++j)
                dist += abs(key - v[j]);

            printf("%d\n", dist);

        }
    }
    return 0;
}
