#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

struct Movie {
    string title;
    string genre;
    int releaseYear;
    string director;
    double rating;
};


// Function to recommend a movie
void recommendMovie(const vector<Movie> &movies, const string &genre)
{
    vector<Movie> recommendedMovies;

    // Find movies with matching genre
    for (const auto &movie : movies)
    {
        if (movie.genre == genre)
        {
            recommendedMovies.push_back(movie);
        }
    }

    // Check if any movies found
    if (recommendedMovies.empty())
    {
        cout << "Sorry, no movies found in the specified genre." << endl;
    }
    else
    {
        // Select a random movie from the recommended list
        int randomIndex = rand() % recommendedMovies.size();
        const Movie &recommendedMovie = recommendedMovies[randomIndex];

        cout << "Recommended movie: " << recommendedMovie.title << endl;
    }
}


void getInfo(const vector<Movie> &movies, const string &moviee){

    vector<string> mv;
    float flt=0.0;
     for (const auto &movie : movies)
    {
        if (movie.title == moviee)
        {   
            mv.push_back(movie.title);
            mv.push_back(movie.genre);
            mv.push_back(to_string(movie.releaseYear));
            mv.push_back(movie.director);
            flt=movie.rating;
            break;
        }
    }

     if (mv.empty()) {
        cout << "Sorry, no movies found in the specified genre." << endl;
    } else {

        cout << "Recommended movie: " << mv[0] << endl;
        cout << "Genre: " << mv[1] << endl;
        cout << "Release Year: " << mv[2] << endl;
        cout << "Director: " << mv[3] << endl;
        cout << "Rating: "<<flt << "/10" << endl;
    }
}

void sortMovies(const vector<Movie> &movies,const int x){
    
    vector<pair<double,string>> top;

    for(const auto &movie : movies){
        top.push_back(make_pair(movie.rating,movie.title));
    }

    sort(top.begin(), top.end(), greater <>());

    cout<<"Top "<<x<<" movies are: "<<endl;

    cout<<"Sr No."<<"\tRating\t"<<"Name"<<endl;
    int i=0;
    for(auto a:top){
        i++;
        if(i==x+1) break;
        cout<<i<<"\t"<<a.first<<"\t"<<a.second<<endl;
    }

}

int main()
{

     vector<Movie> moviesE = {
        {"The Shawshank Redemption", "Drama", 1994, "Frank Darabont", 9.3},
        {"Inception", "Sci-Fi", 2010, "Christopher Nolan", 8.8},
        {"The Dark Knight", "Action", 2008, "Christopher Nolan", 9.0},
        {"Pulp Fiction", "Crime", 1994, "Quentin Tarantino", 8.9},
        {"Fight Club", "Drama", 1999, "David Fincher", 8.8},
        {"The Matrix", "Sci-Fi", 1999, "The Wachowski Brothers", 8.7},
        {"Goodfellas", "Crime", 1990, "Martin Scorsese", 8.7},
        {"The Godfather", "Crime", 1972, "Francis Ford Coppola", 9.2},
        {"Interstellar", "Sci-Fi", 2014, "Christopher Nolan", 8.6},
        {"The Departed", "Crime", 2006, "Martin Scorsese", 8.5}
    };
        vector<Movie> moviesH = {
        {"Dilwale Dulhania Le Jayenge", "Romance", 1995, "Aditya Chopra", 9.1},
        {"Sholay", "Action", 1975, "Ramesh Sippy", 8.2},
        {"Lagaan", "Sport", 2001, "Ashutosh Gowariker", 8.1},
        {"Kabhi Khushi Kabhie Gham", "Drama, Musical, Romance", 2001, "Karan Johar", 7.4},
        {"3 Idiots", "Comedy", 2009, "Rajkumar Hirani", 8.4},
        {"PK", "Comedy", 2014, "Rajkumar Hirani", 8.1},
        {"Dangal", "Action", 2016, "Nitesh Tiwari", 8.4},
        {"Kuch Kuch Hota Hai", "Drama", 1998, "Karan Johar", 7.6},
        {"Kabir Singh", "Romance", 2019, "Sandeep Reddy Vanga", 7.1},
        {"Bajrangi Bhaijaan", "Action", 2015, "Kabir Khan", 8.0}
    };
    vector<Movie> moviesM = {
        {"Sairat", "Romance, Drama", 2016, "Nagraj Manjule", 8.4},
        {"Natsamrat", "Drama", 2016, "Mahesh Manjrekar", 8.9},
        {"Shwaas", "Drama", 2004, "Sandesh Kulkarni", 8.3},
        {"Court", "Drama", 2014, "Chaitanya Tamhane", 7.7},
        {"Katyar Kaljat Ghusali", "Musical, Drama", 2015, "Subodh Bhave", 8.2},
        {"Fandry", "Drama", 2013, "Nagraj Manjule", 8.1},
        {"Deool", "Drama", 2011, "Umesh Vinayak Kulkarni", 7.9},
        {"Harishchandrachi Factory", "Biography, Drama", 2009, "Paresh Mokashi", 8.1},
        {"Natarang", "Musical, Drama", 2010, "Ravi Jadhav", 8.3},
        {"Kaksparsh", "Drama", 2012, "Mahesh Manjrekar", 7.7}
    };


    cout << "Welcome to the movie recommendation chatbot!" << endl;
    string lang;
    cout<<"Enter the Language of Movies You want: ";
    getline(cin,lang);

    while (true)
    {
        string input;
        cout << "User: ";
        getline(cin, input);
        if (input == "exit")
        {
            break;
        }
        else if (input == "recommend a movie")
        {
            cout << "Enter your preferred genre: ";
            getline(cin, input);
            if(lang=="english")
                recommendMovie(moviesE, input);
            else if(lang=="hindi")
                recommendMovie(moviesH, input);
            else
                recommendMovie(moviesM, input);
        }
        else if(input=="info"){
            cout<<"Enter movie name: ";
            getline(cin,input);
            if(lang=="english")
                getInfo(moviesE,input);
            else if(lang=="hindi")
                getInfo(moviesH,input);
            else
                getInfo(moviesM,input);
            
        }
        else if(input=="top x movies"){
            cout<<"Enter value of x: ";
            int x; cin>>x;
            if(lang=="english")
                sortMovies(moviesE,x);
            else if(lang=="hindi")
                sortMovies(moviesH,x);
            else
                sortMovies(moviesM,x);
        }
        cout<<endl;
    }

    return 0;
}
