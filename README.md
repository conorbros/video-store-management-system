# Video Store Management System

## Brief

This project was part of the assessment in my Algorithms and Complexity class.

## Usage

To run the project, clone the repo and nagivate to the directory in your terminal. Run the following to compile the program.

```bash
make
```

Then run the following to start the program.

```bash
./bin/main
```

## Notes

The project contains some prefilled data to make testing the software easier, to remove this comment out line 475 in ```src/main.cpp```

## Top 10 Algorithm Analysis 

Top 10 Algorithm
```
ALGORITHM GetIndex(Movies[10], Movie, Count)
    // Gets the index that the supplied Movie should be inserted into
    // Inputs: An array Movies containing the current largest elements, 
    // Movie the Movie to insert
    // Count the number of Movies in the Movies Array
    // Output: Returns the index
 
Ans ← -1 
L ← 0
R ← Count - 1
    
    while L ≤ R
        M ← (L + R) / 2
        
        If Movies[M] ＝ Movie
            return M
        
        else if Movies[M] < Movie
            Ans ← M
            L ← M + 1
        
        else
            R ← M - 1

    return Ans + 1
```
The basic operation chosen for this algorithm is the comparisons between Movies[M] and Movie. The best case is where the index for the new movie is to be inserted at is the exact midpoint with an efficiency of O(1). The worst case is when the new index is at the front or the end of the array. The time complexity for this case is O(log n + 1). Since the array will have a maximum of 10 elements, this means that the worst case efficiency will be O(log 10 + 1) since log(10) and 1 are constant values. Meaning the overall efficiency is O(1).
```
ALGORITHM AddToArray(Movies[10], Movie, Count)
    // Adds the supplied Movie to the Movies Array
    // Input: Movies: array to add Movie to. Count: number of Movies already in the array

    if Count ＝ 0
        Movies[0] ← Movie
        return
            
    Location <- GetIndex(Movies, Movie, Count)

    if Count < 10
        for I ← Count to Location - 1
            Movies[I] ← Movies[I - 1]

    else
        for I ← 0 to Location - 1
            Movies[I] ← Movies[I + 1]
        
        Location ← Location - 1
    
    Movies[Location] ← Movies
```
The best case for this algorithm will only occur once, when the count is zero and the only index available to insert at is 0. The efficiency is O(1) in this case. The worst case happens when every Movie has to be added to the end of Array, meaning that the worst case complexity of O(1) will occur and all the elements must be shifted back one place to make room for the new Movie at the end of the Movies array which is the largest shift that can occur. The basic operation chosen for this algorithm is the array shifting in the if else block. When the Count is below 10, everything after the new index must be pushed forward, whereas when the count is above 10, everything behind the new location must be pushed back, which pushes the smallest element out of the array to make space for the new one. When Count is below 10, the operation takes O(Count - Location), with n being the location of the new element, since both are guaranteed to be below 10, this is O(1). When the Count is above 10, the operation takes O(Location), since Location is guaranteed to be below 10, the efficiency is O(1). Thus the overall efficiency for this algorithm is O(1).
```
ALGORITHM GetTopTen(Movies[10], Count, T)
    // Traverses the binary search tree in order and fills the supplied array with the 10 largest 
    // elements. 
    // Inputs: Movies: the array to fill. Count: The number of movies in the array, is initially 0.
    // T: the root node of the binary search tree
    // Output: The updated Count after performing operations on a Node
    
    if T ＝ NULL
        return Count
    
    Count ← GetTopTen(Movies, Count, T→Left)
    
    if Count < 10
        AddToArray(Movies, Count, T→Movie)
        Count ← Count + 1
    
    else if T→Movie > Movies[0]
        AddToArray(Movies, Count, T→Movie)
    
    Count ← GetTopTen(Movies, Count, T→Right)

    return Count
```

This algorithm comprises of recursive calls to itself, an in order traversal of the binary search tree and AddToArray. This basic operation chosen for this algorithm is checking if Count is below 10 or going to the else block. This algorithm traverses the entire binary search tree and performs this operation at each node.

The best case for this algorithm is that the first 10 nodes are the largest and thus AddToArray is only called 10 times and then not called again for the rest of the binary search tree traversal. Thus the best case time complexity is O(n), where n represents the count of nodes in the tree.

The worst case for this algorithm is that after the first 10 movies are added to the array, each movie that comes after is larger than the movies already in the array which means that AddToArray is called a total of n times. Since each call to AddToArray takes O(1) the overall worst case efficiency is O(n).

