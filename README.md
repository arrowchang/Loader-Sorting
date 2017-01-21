# Loader-Sorting
A sort method to minimize the steps &amp; distance in real world.
The code is written in 2012 when I was an undergraduatestudent in college. It's a abstraction of a real life problem —— how to organize the books in a library as a robot.
A book has a unique bookmark, it tells what the classification the book is and in which bookshelf you can find it. But unfortunately, some books may located in wrong place. So if a robot can read the bookmark, by a scanner or RFID reader, how can it find out the wrong-placement book(s)? It's a simple question, however, if you think it twice it won't be that simple. A book is not a bit in the chip any more, move it will cost huge time and energys for a robot. Classical sorting methods no longer working here. 
Let alone the details, at last we can abstract this problem to a mathematic model. Supposing there is a array, how can one move the minimum steps as well as fewest distance to make it in order? //The "sub-distance" is defined by "the elements between it's settled position and it's original position", and the “distance” is the sum of the sub-distance of the whole processing.
You can run mysort.exe directly to see the results:
Type in a random sequence, each element separated by a " " and end the input by pressing "ENTER". Then it will display the detailed steps to show how to move.
*The code is in a mess and I cannot understand it now. If you are interested, please help improving it. Hope it helps. 
