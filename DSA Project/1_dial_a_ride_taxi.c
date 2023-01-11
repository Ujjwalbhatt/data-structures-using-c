#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LOCATIONS 100
#define MAX_VEHICLES 25
#define MAX_CAPACITY 5
#define MAX_REQUESTS 5000

struct Request
{
    int pick_up_location;
    int drop_off_location;
    int pick_up_time;
    int drop_off_time;
};

struct Vehicle
{
    int current_location;
    int capacity;
    int schedule[MAX_REQUESTS];
    int num_scheduled;
};

int distances[MAX_LOCATIONS][MAX_LOCATIONS];
struct Request requests[MAX_REQUESTS];
struct Vehicle vehicles[MAX_VEHICLES];

void compute_shortest_distances()
{
    // Use Floyd-Warshall algorithm to compute shortest distances between all pairs of locations
    for (int k = 0; k < MAX_LOCATIONS; k++)
    {
        for (int i = 0; i < MAX_LOCATIONS; i++)
        {
            for (int j = 0; j < MAX_LOCATIONS; j++)
            {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX && distances[i][j] > distances[i][k] + distances[k][j])
                {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }
}

int compute_shortest_distance(int start, int end)
{
    // Use Dijkstra's algorithm to find the shortest distance from start to end
    int distances[MAX_LOCATIONS];
    int visited[MAX_LOCATIONS];
    // Set all distances to infinity
    for (int i = 0; i < MAX_LOCATIONS; i++)
    {
        distances[i] = INT_MAX;
    }
    // Set all locations to unvisited
    for (int i = 0; i < MAX_LOCATIONS; i++)
    {
        visited[i] = 0;
    }
    distances[start] = 0;
    for (int i = 0; i < MAX_LOCATIONS; i++)
    {
        // Find the unvisited location with the shortest distance
        int min_distance = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < MAX_LOCATIONS; j++)
        {
            if (!visited[j] && distances[j] < min_distance)
            {
                min_distance = distances[j];
                min_index = j;
            }
        }
        if (min_index == -1)
        {
            break;
        }
        visited[min_index] = 1;
        // Update the distances to unvisited neighboring locations
        for (int j = 0; j < MAX_LOCATIONS; j++)
        {
            // If the distance to the neighboring location is not infinity and the distance to the neighboring location is greater than the distance to the current location plus the distance from the current location to the neighboring location, update the distance to the neighboring location
    
            if (!visited[j] && distances[j] != INT_MAX && distances[j] > distances[min_index] + distances[min_index * MAX_LOCATIONS + j])
            {
                distances[j] = distances[min_index] + distances[min_index * MAX_LOCATIONS  + j];
            }
        }
    }
    return distances[end];
}

void schedule_requests()
{
    // Sort requests by pick-up time
    qsort(requests, MAX_REQUESTS - 1, sizeof(struct Request), compare_requests);
    // Schedule requests
    for (int i = 0; i < MAX_REQUESTS; i++)
    {
        int min_distance = INT_MAX;
        int min_index = -1;
        // Find the vehicle with the shortest distance to the pick-up location
        for (int j = 0; j < MAX_VEHICLES; j++)
        {
            int distance = compute_shortest_distance(vehicles[j].current_location, requests[i].pick_up_location);
            if (distance < min_distance)
            {
                min_distance = distance;
                min_index = j;
            }
        }
        // Add the request to the vehicle's schedule
        vehicles[min_index].schedule[vehicles[min_index].num_scheduled] = i;
        vehicles[min_index].num_scheduled++;
        vehicles[min_index].current_location = requests[i].drop_off_location;
    }
}

int compare_requests(const void *a, const void *b)
{
    struct Request *request_a = (struct Request *)a;
    struct Request *request_b = (struct Request *)b;
    return request_a->pick_up_time - request_b->pick_up_time;
}

int main()
{
    // Read distances between locations
    for (int i = 0; i < MAX_LOCATIONS; i++)
    {
        for (int j = 0; j < MAX_LOCATIONS; j++)
        {
            scanf("%d", &distances[i][j]);
        }
    }
    // Read requests
    for (int i = 0; i < MAX_REQUESTS; i++)
    {
        scanf("%d %d %d %d", &requests[i].pick_up_location, &requests[i].drop_off_location, &requests[i].pick_up_time, &requests[i].drop_off_time);
    }
    // Compute shortest distances between all pairs of locations
    compute_shortest_distances();
    // Initialize vehicles
    for (int i = 0; i < MAX_VEHICLES; i++)
    {
        vehicles[i].current_location = 0;
        vehicles[i].capacity = MAX_CAPACITY;
        vehicles[i].num_scheduled = 0;
    }
    // Schedule requests
    schedule_requests();
    // Print schedules
    for (int i = 0; i < MAX_VEHICLES; i++)
    {
        printf("Vehicle %d: ", i);
        for (int j = 0; j < vehicles[i].num_scheduled; j++)
        {
            printf("%d ", vehicles[i].schedule[j]);
        }
        printf("");
    }
    return 0;
}
