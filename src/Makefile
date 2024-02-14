program:Main
	g++ Main.o MainTree2.o MainTree1.o LLRBTree.o AVLTree.o PrintFuncs.o -o webstore
Main: PrintFuncs
	g++ -c Main.cpp -o Main.o
PrintFuncs: AVLTree LLRBTree MainTree1 MainTree2
	g++ -c PrintFuncs.cpp -o PrintFuncs.o
AVLTree: 
	g++ -c AVLTree.cpp -o AVLTree.o
LLRBTree:
	g++ -c LLRBTree.cpp -o LLRBTree.o
MainTree1:
	g++ -c MainTree1.cpp -o MainTree1.o
MainTree2:
	g++ -c MainTree2.cpp -o MainTree2.o


