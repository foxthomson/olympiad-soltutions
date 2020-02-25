#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int lengths[1000000];
int point[1000000];
vector<int> pointed[1000000];
bool visitedA[1000000];
bool visitedB[1000000];
bool loop[1000000];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int length;
    int pointto;
    cin >> pointto >> length;
    pointto--;
    lengths[i] = length;
    point[i] = pointto;
    pointed[pointto].push_back(i);
  }

  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (visitedB[i]) continue;

    // cout << i << " ";

    int curr = i;
    while (!visitedA[curr])
    {
      // cout << curr << endl;
      visitedA[curr] = true;
      curr = point[curr];
    }

    int p = curr;

    // cout << 100 << endl;

    int loopsize = 0;
    while (!loop[curr])
    {
      loopsize += lengths[curr];
      loop[curr] = true;
      curr = point[curr];
    }

    // cout << 200 << endl;

    {
      queue<int> nodes;
      queue<long long> distances;

      long long maxdist = 0;
      int maxnode = p;

      long long currlength = lengths[p];
      curr = point[p];
      while (curr != p)
      {
        nodes.push(curr);
        long long dist;
        if (2*currlength > loopsize)
        {
          dist = currlength;
          // distances.push(currlength);
        }
        else
        {
          dist = loopsize - currlength;
          // distances.push(loopsize-currlength);
        }
        distances.push(dist);

        // if (dist > maxdist)
        // {
        //   maxdist = dist;
        //   maxnode = curr;
        // }

        currlength += lengths[curr];
        curr = point[curr];
      }

      for (int j = 0; j < pointed[p].size(); j++)
      {
        if (!loop[pointed[p][j]])
        {
          nodes.push(pointed[p][j]);
          distances.push(lengths[pointed[p][j]]);
        }
      }

      // cout << 300 << endl;

      while (!nodes.empty())
      {
        int node = nodes.front();
        long long dist = distances.front();
        nodes.pop();
        distances.pop();
        // cout << node << " " << dist << endl;

        if (dist > maxdist)
        {
          maxdist = dist;
          maxnode = node;
        }

        for (int j = 0; j < pointed[node].size(); j++)
        {
          if (!loop[pointed[node][j]])
          {
            nodes.push(pointed[node][j]);
            distances.push(dist + lengths[pointed[node][j]]);
          }
        }
      }

      p = maxnode;
      // cout << maxnode << "-";
    }

    {
      queue<int> nodes;
      queue<long long> distances;

      long long maxdist = 0;
      int maxnode = p;

      nodes.push(p);
      distances.push(0);
      visitedB[p] = true;

      // currlength = lengths[p];
      // curr = point[p];
      // while (curr != p)
      // {
      //   nodes.push(curr);
      //   long long dist;
      //   if (2*currlength > loopsize)
      //   {
      //     dist = currlength;
      //     // distances.push(currlength);
      //   }
      //   else
      //   {
      //     dist = loopsize - currlength;
      //     // distances.push(loopsize-currlength);
      //   }
      //   distances.push(dist);
      //
      //   // if (dist > maxdist)
      //   // {
      //   //   maxdist = dist;
      //   //   maxnode = curr;
      //   // }
      //
      //   currlength += lengths[curr];
      //   curr = point[curr];
      // }

      // for (int j = 0; j < pointed[p].size(); j++)
      // {
      //   nodes.push(pointed[p][j]);
      //   distances.push(lengths[pointed[p][j]]);
      // }

      bool looped = false;

      // cout << 400 << endl;

      while (!nodes.empty())
      {
        int node = nodes.front();
        long long dist = distances.front();
        // cout << node << "  " << dist << endl;
        nodes.pop();
        distances.pop();

        if (dist > maxdist)
        {
          maxdist = dist;
          maxnode = node;
        }

        for (int j = 0; j < pointed[node].size(); j++)
        {
          if (!loop[pointed[node][j]] && !visitedB[pointed[node][j]])
          {
            nodes.push(pointed[node][j]);
            distances.push(dist + lengths[pointed[node][j]]);
            visitedB[pointed[node][j]] = true;
          }
        }

        if (!loop[node] && !visitedB[point[node]])
        {
          nodes.push(point[node]);
          distances.push(dist + lengths[node]);
          visitedB[point[node]] = true;
        }

        if (!looped && loop[node])
        {
          looped = true;
          p = node;
          long long currlength = lengths[p];
          curr = point[p];
          while (curr != p)
          {
            nodes.push(curr);
            visitedB[curr] = true;
            long long pushdist;
            if (2*currlength > loopsize)
            {
              pushdist = currlength;
              // distances.push(currlength);
            }
            else
            {
              pushdist = loopsize - currlength;
              // distances.push(loopsize-currlength);
            }
            distances.push(pushdist + dist);

            // if (dist > maxdist)
            // {
            //   maxdist = dist;
            //   maxnode = curr;
            // }

            currlength += lengths[curr];
            curr = point[curr];
          }
        }
      }

      // cout << maxnode << " " << maxdist << endl;
      ans += maxdist;
    }
  }

  cout << ans << endl;

  return 0;
}
