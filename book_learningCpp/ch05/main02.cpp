#include <iostream>

float average_rating(int movie_rating[], int num_users)
{
    // average rating for movie 1 is calculated by adding all the ratings and dividing by the number of ratings
    int sum = 0;
    int legit_ratings = 0;
    for (int i = 0; i < num_users; i++)
    {
        if (movie_rating[i] > -1)
        {
            sum += movie_rating[i];
            legit_ratings++;
        }
    }
    return static_cast<float>(sum) / legit_ratings;
}

int main()
{
    const int num_movies = 5;
    const int num_users = 5;
    // movie rating array; rows are movies, columns are user ratings
    // the last element in each row is -1 to indicate the end of the row / unused user ratings
    int movie_rating[num_movies][num_users] = 
    {
        {1, 4, 3, 5, -1},
        {2, 3, 3, 5, -1},
        {1, 4, 4, 5, -1},
        {3, 4, 3, 4, -1},
        {3, 4, 3, 5, -1}
    };

    float movie_avg_rating[num_movies];
    for (int i = 0; i < num_movies; i++)
    {
        movie_avg_rating[i] = average_rating(movie_rating[i], num_users);
    }

    for ( int i = 0; i < num_movies; i++)
    {
        std::cout << "movie " << i + 1 << " average rating is " << movie_avg_rating[i] << std::endl;
    }

    return 0;
}