DiscussionForum:  main.o Forum.o Thread.o Post.o Date.o PostList.o ThreadList.o Tree.o PrintSorted.o
	g++  -o forum main.o Forum.o Thread.o Post.o Date.o	PostList.o ThreadList.o Tree.o PrintSorted.o

main.o: main.cpp
	g++ -g -c  main.cpp

Forum.o: Forum.cpp Forum.h
	g++ -g -c Forum.cpp

Thread.o: Thread.cpp Thread.h
	g++ -g -c Thread.cpp

Post.o: Post.cpp Post.h
	g++ -g -c Post.cpp

Date.o: Date.cpp Date.h
	g++ -g -c Date.cpp

PostList.o: PostList.cpp PostList.h
	g++ -g -c PostList.cpp

ThreadList.o: ThreadList.cpp ThreadList.h
	g++ -g -c ThreadList.cpp

Tree.o: Tree.cpp Tree.h
	g++ -g -c Tree.cpp

PrintSorted.o: PrintSorted.cpp PrintSorted.h
	g++ -g -c PrintSorted.cpp

clean:
	rm *.o forum
