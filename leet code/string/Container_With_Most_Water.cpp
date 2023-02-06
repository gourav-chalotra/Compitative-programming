// Level - Medium
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int length = height.size() - 1;
        int frount = 0;
        int rear = length;
        int maxWaterContainer = 0;
        while (frount < rear)
        {
            if (height[frount] < height[rear])
            {
                if (maxWaterContainer < (height[frount]) * (rear - frount))
                {
                    cout << "frount: " << height[frount] << " rear: " << height[rear] << endl;
                    maxWaterContainer = (height[frount]) * (rear - frount);
                    cout <<"if max value are: "<< maxWaterContainer << endl;
                }
                frount++;
            }               
            else if (height[frount] > height[rear])
            {
                cout << maxWaterContainer << endl;
                if (maxWaterContainer < (height[rear]) * (rear - frount))
                {
                    cout << "frount: " << height[frount] << " rear: " << height[rear] << endl;
                    maxWaterContainer = (height[rear]) * (rear - frount);
                    cout <<"else if max value are: "<< maxWaterContainer << endl;
                }
                rear--;
            }
            else
            {
                if (maxWaterContainer < (height[frount]) * (rear - frount))
                {
                    cout << "frount: " << height[frount] << " rear: " << height[rear] << endl;
                    maxWaterContainer = (height[frount]) * (rear - frount);
                    cout <<"else max value are: "<< maxWaterContainer << endl;
                }
                rear--;
                frount++;
                cout << "else: " << endl;
            }
        }
        return maxWaterContainer;
    }
};

// Answer 42