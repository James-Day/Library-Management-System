//#include "manager.h"
#include "fiction_book.h"
#include "childrens_book.h"
#include "periodical.h"         //I will remove these later
#include "bintree.h"
#include "library.h"

using namespace std;

bool test(bool expected, bool real, string testName) {
    if (expected == real) {
        cout << "TEST " << testName << " PASSED!" << endl;
        return true;
    }
    cout << "TEST " << testName << " FAILED --------------------------" << endl;
    return false;
}

int main() {
    //Manager manager;
    //manager.inputMediaFile("filename.txt");
    //manager.inputPatreonFile("filename.txt");
    //manager.inputTransactions("filename.txt");
    FictionBook Fbook1;
    FictionBook Fbook2;
    FictionBook Fbook3;
    FictionBook Fbook4;
    FictionBook Fbook5;
    FictionBook Fbook6;
    FictionBook Fbook7;
    FictionBook FsameAuthor;
    FictionBook FsameAuthor2;
    FictionBook Fbook52;
    FictionBook Fdisplay;
    FictionBook Fdisplay2;


    ChildrensBook Cbook1;
    ChildrensBook Cbook2;
    ChildrensBook Cbook3;
    ChildrensBook Cbook4;
    ChildrensBook Cbook5;
    ChildrensBook Cbook6;
    ChildrensBook Cbook7;
    ChildrensBook CsameAuthor;
    ChildrensBook CsameAuthor2;
    ChildrensBook Cbook52;
    ChildrensBook Cdisplay;

    Periodical Pbook1;
    Periodical Pbook2;
    Periodical Pbook3;
    Periodical Pbook4;
    Periodical Pbook5;
    Periodical Pbook6;
    Periodical Pbook7;
    Periodical Pdiffcopies;
    Periodical P1;
    Periodical P2;
    Periodical P3;
    Periodical P4;
    Periodical P5;
    Periodical P6;
    Periodical Pdisplay;

    //book1.display();
    Fbook3.changevals("", 1996, "FactoryFictionBook", 1);
    Fbook4.changevals("", 1996, "difTitle", 1);
    Fbook5.changevals("difAuth", 1996, "FactoryFictionBook", 1);
    Fbook6.changevals("", 2000, "FactoryFictionBook", 1);
    Fbook7.changevals("aaaa", 2000, "FactoryFictionBook", 1);
    FsameAuthor.changevals("bbb", 1754, "FactoryFictionBook", 1);
    FsameAuthor2.changevals("bbb", 2000, "Factoryc", 1);
    Fbook52.changevals("a", 1996, "ZZZZ", 1);
    Fdisplay.changevals("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaad", 1996888, "ZZZZaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaad", 1);
    Fdisplay2.changevals("Daheim Mary", 1991, "Fowl Prey", 5);

    Cbook3.changevals("", 1996, "FactoryChildrensBook", 1);
    Cbook4.changevals("", 1996, "difTitle", 1);
    Cbook5.changevals("difAuth", 1996, "FactoryFictionBook", 1);
    Cbook6.changevals("", 2000, "FactoryFictionBook", 1);
    Cbook7.changevals("aaaa", 2000, "FactoryFictionBook", 1);
    CsameAuthor.changevals("bbb", 1754, "FactoryFictionBook", 1);
    CsameAuthor2.changevals("bbb", 2000, "Factoryc", 1);
    Cbook52.changevals("a", 1996, "ZZZZ", 1);
    Cdisplay.changevals("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaad", 1996888, "ZZZZaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaad", 1);

    Pbook3.changevals(0, 1996, "FactoryPeriodical", 1);
    Pbook4.changevals(0, 1996, "difTitle", 1);
    Pbook5.changevals(0, 1111, "FactoryPeriodical", 1);
    Pbook6.changevals(1, 2000, "FactoryPeriodical", 1);
    Pbook7.changevals(0, 2000, "FactoryPeriodical", 1);
    Pdiffcopies.changevals(0, 2000, "FactoryPeriodical", 2);
    P1.changevals(0, 9999, "title", 1);
    P2.changevals(0, 9998, "title", 1);
    P3.changevals(3, 9998, "title", 1);
    P4.changevals(5, 9998, "title", 1);
    P5.changevals(10, 9999, "title", 1);
    P6.changevals(10, 9999, "aaa", 1);
    Pdisplay.changevals(1111, 1996888, "ZZZZaaaaaaaasdaaaaaaaaaaaaaaaaaaaaaaaaaaad", 1);



    cout << endl << endl << "   TESTING FICTION BOOK" << endl << endl;

    ///////////////////////// FICTION BOOK ///////////////////////////////////


    //TESTING == FICTIONBOOK
    test(true, Fbook1 == Fbook1, "Self Equivalence");
    test(true, Fbook1 == Fbook2, "Equivalence");
    test(true, Fbook1 == Fbook3, "Equivalence 2");
    test(false, Fbook1 == Fbook4, "non Equivalence");
    test(false, Fbook1 == Fbook5, "non Equivalence 2");
    test(false, Fbook1 == Fbook6, "non Equivalence 3");
    test(false, Fbook2 == Fbook5, "non Equivalence 4");

    //TESTING < FICTIONBOOK
    test(false, Fbook1 < Fbook1, "Self Check <");
    test(false, Fbook1 < Fbook2, "Same value <");
    test(true, Fbook7 < Fbook5, "normal <");
    test(true, FsameAuthor < FsameAuthor2, "Same Author <");
    test(false, Fbook5 < Fbook7, "normal false <");
    test(false, FsameAuthor2 < FsameAuthor, "Same Author false <");
    test(false, Fbook5 < Fbook52, "correct order of sort");

    //TESTING > FICTIONBOOK
    test(false, Fbook1 > Fbook1, "Self Check >");
    test(false, Fbook1 > Fbook2, "Same value >");
    test(true, Fbook5 > Fbook7, "normal >");
    test(true, FsameAuthor2 > FsameAuthor, "Same Author >");
    test(false, Fbook7 > Fbook5, "normal false >");
    test(false, FsameAuthor > FsameAuthor2, "Same Author false >");
    test(true, Fbook5 > Fbook52, "correct order of sort");

    cout << endl << endl << "   TESTING CHILDRENS BOOK" << endl << endl;


    ///////////////////////// CHILDRENS BOOK /////////////////////////////////
    
    //TESTING == CHILDRENSBOOK
    test(true, Cbook1 == Cbook1, "Self Equivalence");
    test(true, Cbook1 == Cbook2, "Equivalence");
    test(true, Cbook1 == Cbook3, "Equivalence 2");
    test(false, Cbook1 == Cbook4, "non Equivalence");
    test(false, Cbook1 == Cbook5, "non Equivalence 2");
    test(false, Cbook1 == Cbook6, "non Equivalence 3");
    test(false, Cbook2 == Cbook5, "non Equivalence 4");

    //TESTING < CHILDRENSBOOK
    test(false, Cbook1 < Cbook1, "Self Check <");
    test(false, Cbook1 < Cbook2, "Same value <");
    test(true, Cbook7 < Cbook5, "normal <");
    test(true, CsameAuthor < CsameAuthor2, "Same Author <");
    test(false, Cbook5 < Cbook7, "normal false <");
    test(false, CsameAuthor2 < CsameAuthor, "Same Author false <");
    test(true, Cbook5 < Cbook52, "correct order of sort");

    //TESTING > CHILDRENSBOOK
    test(false, Cbook1 > Cbook1, "Self Check >");
    test(false, Cbook1 > Cbook2, "Same value >");
    test(true, Cbook5 > Cbook7, "normal >");
    test(true, CsameAuthor2 > CsameAuthor, "Same Author >");
    test(false, Cbook7 > Cbook5, "normal false >");
    test(false, CsameAuthor > CsameAuthor2, "Same Author false >");
    test(false, Cbook5 > Cbook52, "correct order of sort");

    cout << endl << endl << "   TESTING PERIODICALS" << endl << endl;


    ///////////////////////// PERIODICAL BOOK ////////////////////////////////
    
     //TESTING == PERIODICAL
    test(true, Pbook1 == Pbook1, "Self Equivalence");
    test(true, Pbook1 == Pbook2, "Equivalence");
    test(true, Pbook1 == Pbook3, "Equivalence 2");
    test(true, Pdiffcopies == Pbook7, " Equivalence 3");
    test(false, Pbook1 == Pbook4, "non Equivalence");
    test(false, Pbook1 == Pbook5, "non Equivalence 2");
    test(false, Pbook1 == Pbook6, "non Equivalence 3");
    test(false, Pbook2 == Pbook5, "non Equivalence 4");
    
    //TESTING < PERIODICAL
    test(false, Pbook1 < Pbook1, "Self Check <");
    test(false, Pbook1 < Pbook2, "Same value <");
    test(true, P2 < P1, "normal <");
    test(false, P1 < P2, "normal false <");
    test(true, P2 < P3, "Month <");
    test(false, P3 < P2, "Month false <");
    test(true, P4 < P1, "Year and Month <");
    test(false, P1 < P4, "Year and Month false <");
    test(true, P2 < P5, "Year and Month larger  <");
    test(false, P5 < P2, "Year and Month larger false <");
    test(true, P6 < P5, "sort by title <");
    test(false, P5 < P6, "sort by title2 <");

    cout << endl << endl << "   TESTING BOOK DISPLAYS" << endl << endl;

    ///////////////////////// EXTRA BOOK TESTING /////////////////////////////
    //test(false, Pbook1 < Fbook1, "MultiBookCheck <");   //ASK PROF ABOUT THIS
    // TEST DISPLAYS
    Media* a = &Fbook1;

    Fdisplay2.display();
    cout << endl;
    a = &Cdisplay;
    a->display();
    cout << endl;
    a = &Pdisplay;
    a->display();

    cout << endl << endl << "   TESTING BSTREE" << endl << endl;

    ///////////////////////// BSTREE TESTING //////////////////////////////////
        
    cout << endl <<  "   TESTING FICTIONBOOK SORTING" << endl;

    //TESTING FICTIONBOOKS SORTING
    FictionBook* a1 = new FictionBook();
    FictionBook* b = new FictionBook();
    FictionBook* c = new FictionBook();
    FictionBook* d = new FictionBook();
    FictionBook* e = new FictionBook();
    FictionBook* f = new FictionBook();
    FictionBook* g = new FictionBook();
    FictionBook* h = new FictionBook();
    FictionBook* i = new FictionBook();

    a1->changevals("aaa", 2000, "FactoryFictionBook", 1);
    b->changevals("bbb", 2000, "FactoryFictionBook", 1);
    c->changevals("ccc", 2000, "FactoryFictionBook", 1);
    d->changevals("ddd", 2000, "FactoryFictionBook", 1);
    e->changevals("eee", 2000, "FactoryFictionBook", 1);
    f->changevals("fff", 2000, "factoryFictionBook", 1);
    g->changevals("fff", 2000, "aaa", 4);
    h->changevals("fff", 2000, "bbb", 2);
    i->changevals("fff", 2000, "ccc", 3);

    BinTree tree1;
    tree1.insert(c);
    tree1.insert(a1);
    tree1.insert(b);
    tree1.insert(d);
    tree1.insert(e);
    tree1.insert(f);
    tree1.insert(g);
    tree1.insert(h);
    tree1.insert(i);

    cout << tree1;

    cout << endl << "   TESTING CHILDRENSBOOK SORTING" << endl;

    //TESTING CHILDRENSBOOKS SORTING
    ChildrensBook* a2 = new ChildrensBook();
    ChildrensBook* b2 = new ChildrensBook();
    ChildrensBook* c2 = new ChildrensBook();
    ChildrensBook* d2 = new ChildrensBook();
    ChildrensBook* e2 = new ChildrensBook();
    ChildrensBook* f2 = new ChildrensBook();
    ChildrensBook* g2 = new ChildrensBook();
    ChildrensBook* h2 = new ChildrensBook();
    ChildrensBook* i2 = new ChildrensBook();

    a2->changevals("aaa", 2000, "FactoryFictionBook", 1);
    b2->changevals("bbb", 2000, "FactoryFictionBook", 1);
    c2->changevals("ccc", 2000, "FactoryFictionBook", 1);
    d2->changevals("ddd", 2000, "FactoryFictionBook", 1);
    e2->changevals("eee", 2000, "FactoryFictionBook", 1);
    f2->changevals("zzz", 2000, "factoryFictionBook", 1);
    g2->changevals("fff", 2000, "aaa", 4);
    h2->changevals("fff", 2000, "bbb", 2);
    i2->changevals("fff", 2000, "ccc", 3);

    BinTree tree2;
    tree2.insert(a2);
    tree2.insert(b2);
    tree2.insert(c2);
    tree2.insert(d2);
    tree2.insert(e2);
    tree2.insert(f2);
    tree2.insert(g2);
    tree2.insert(h2);
    tree2.insert(i2);

    cout << tree2;


    cout << endl << "   TESTING PERIODICALS SORTING" << endl;

    //TESTING PERIODICALS SORTING
    Periodical* a3 = new Periodical();
    Periodical* b3 = new Periodical();
    Periodical* c3 = new Periodical();
    Periodical* d3 = new Periodical();
    Periodical* e3 = new Periodical();
    Periodical* f3 = new Periodical();
    Periodical* g3 = new Periodical();
    Periodical* h3 = new Periodical();
    Periodical* i3 = new Periodical();
    Periodical* j3 = new Periodical();

    a3->changevals(1, 2000, "FactoryFictionBook", 1);
    b3->changevals(2, 2000, "FactoryFictionBook", 1);
    c3->changevals(2, 2000, "FactoryFictionBook", 1);
    d3->changevals(2, 1999, "FactoryFictionBook", 1);
    e3->changevals(3, 2000, "title", 1);
    f3->changevals(1, 2001, "factoryFictionBook", 1);
    g3->changevals(5, 1999, "aaa", 4);
    h3->changevals(2, 1895, "bbb", 2);
    i3->changevals(3, 2005, "ccc", 3);
    j3->changevals(3, 2000, "aaa", 3);

    BinTree tree3;
    tree3.insert(a3);
    tree3.insert(b3);
    tree3.insert(c3);
    tree3.insert(d3);
    tree3.insert(e3);
    tree3.insert(f3);
    tree3.insert(g3);
    tree3.insert(h3);
    tree3.insert(i3);
    tree3.insert(j3);

    cout << tree3;

    cout << endl << "   TESTING BSTREE RETRIEVE" << endl;
    
    //TESTING PERIODICALS SORTING
    Periodical* found = nullptr;
    Media* found2 = (Media*)found;
    tree3.retrieve(*e3, found2);

     Periodical* found2_ptr = dynamic_cast<Periodical*>(found2);
     found2_ptr->display();

     cout << endl << endl << "   TESTING LIBRARY" << endl << endl;

     ///////////////////////// LIBRARY TESTING //////////////////////////////////
}
