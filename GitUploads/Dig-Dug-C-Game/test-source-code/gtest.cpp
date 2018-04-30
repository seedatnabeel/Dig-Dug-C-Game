////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////                              MONSTER HUNTER:DIG DUG EDITION
////////////////                              SOFTWARE DEVELOPMENT 2 (ELEN 3009)
////////////////                              UNIT TESTING USING GOOGLETEST FRAMEWORK

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <gtest/gtest.h>
#include "game.h"

/*         THE UNIT TESTS ARE BASED ON LOGIC AND FUCNTIONALITY. THERE IS NO UNIT TESTING
 *         OF THE SFML LIBRARY FUCNTIONALITY (N GRAPHICS) OR CONTROLS 
 */


// GAME CLASS UNIT TESTS 

TEST(game, DoesGameWindowRenderWithSplash)
{
	//create a new test window
    Window* test_window = new Window(sf::VideoMode(1280, 800), "Dig Dug Window Testing");
    //create an object of game called test1
	game test; 
	//it is expected the window renders correctly and no exception will be thrown
	EXPECT_NO_THROW(test.gamewindow(test_window));
	//the test window must be deleted to automate the test
    delete test_window;
}

TEST(game, srsLossesLivesCorrectly)
{
	//create an object of the game class
	game test;
	
	//decrement the lives of sorceress by 1 in the scoring class 
	// i.e. when sorceress collides with a monster
	test.myscore.srsLives=test.myscore.srsLives-1;
	
	//check the value of lives is correctly updated
	EXPECT_EQ(test.myscore.srsLives,2);
	
}	

TEST(game, startCondsAreCorrect)
{
	//create an object of the game class
	game test;
	
	// check that the 2 game states are initialized correctly
	//win state is false at the start
	//game state (i.e. the game has started) is true
	EXPECT_FALSE(test.win);
	EXPECT_TRUE(test.mygame);
	
}
	
TEST(game, initMonstersAreCorrect)
{
	//create an object of the game class
	game test;
	test.initGenies();
	
	//these are the vector values for the initialized genie positions
	EXPECT_EQ(test.genieVector[0].rect.getPosition().x,960);
	EXPECT_EQ(test.genieVector[0].rect.getPosition().y,480);
	EXPECT_EQ(test.genieVector[1].rect.getPosition().x,240);
	EXPECT_EQ(test.genieVector[1].rect.getPosition().y,640);
	EXPECT_EQ(test.genieVector[2].rect.getPosition().x,-10000);
	EXPECT_EQ(test.genieVector[2].rect.getPosition().y,-10000);
	
}	


// KILLGENIE CLASS UNIT TESTS 


TEST(killGenie, DontEraseGenie)
{
	//create an object of the killgenie class
	killGenie test;
	
	//create a vector of genie objects, as well as, object of genie to pass into the vector
	std::vector<genie> genieVector;
	genie mygenie;
	
	//the function being tested only erases a genie object if the alive state =false
	mygenie.alive=true;// set to true meaning dont erase
	
	//push 2 genie objects into the vector
	mygenie.rect.setPosition(960, 480);
	genieVector.push_back(mygenie);
	mygenie.rect.setPosition(500, 480);
	genieVector.push_back(mygenie);
	unsigned int genieSize=2;
	//call the function being tested
	test.kill_genie(genieVector);
	
	//since the alive state = false, don't erase a genie object, as genie not dead yet
	EXPECT_EQ(genieVector.size(),genieSize);
}
	
TEST(killGenie, EraseGenie)
{
	//create an object of the killgenie class
	killGenie test;
	
	//create a vector of genie objects, as well as, object of genie to pass into the vector
	std::vector<genie> genieVector;
	genie mygenie;
	
	//the function being tested only erases a genie object if the alive state =false
	mygenie.alive=false; //set to false meaning the genie is dead
	
	//push 2 genie objects into the vector
	mygenie.rect.setPosition(960, 480);
	genieVector.push_back(mygenie);
	mygenie.rect.setPosition(500, 480);
	genieVector.push_back(mygenie);
	unsigned int genieSize=1;
	test.kill_genie(genieVector); //call the function being tested
	
	//since the genie alive state is set to false, means the genie is dead and must be erased
	//2 original genie objects in vector, after 1 is erased expect only 1 genie object in the vector
	EXPECT_EQ(genieVector.size(),genieSize);
}	


// SORCERESS CLASS UNIT TESTS 


TEST(sorceress, srsGetXFunctionWorks)
{
	//create a sorceress object
    sorceress srs1;
	
	//check the get_xpos function works
    EXPECT_EQ(srs1.get_xpos(),160);
}


TEST(sorceress, srsGetYFunctionWorks)
{
	//create a sorceress object
    sorceress srs1;
	
	//check the get_ypos function works
    EXPECT_EQ(srs1.get_ypos(),160);
}


TEST(sorceress, srsMovesRight)
{
	//create 2 srs objects
    sorceress srs1;
    sorceress srs2;
	
	//move one object right by calling the moveR function
    srs1.moveR();
	
    //expect direction to be set to 3 = right
	EXPECT_EQ(srs1.direction,3);
	
	//check the positions have changed appropriately
    EXPECT_GT(srs1.get_xpos(),srs2.get_xpos());
	EXPECT_EQ(srs1.get_ypos(),srs2.get_ypos());
}

TEST(sorceress, srsMovesLeft)
{
	//create 2 srs objects
    sorceress srs1;
    sorceress srs2;
	
	//move one object left by calling the moveL function
    srs1.moveL();
	
	 //expect direction to be set to 4 = left
	EXPECT_EQ(srs1.direction,4);
	
	//check the positions have changed appropriately
    EXPECT_LT(srs1.get_xpos(),srs2.get_xpos());
	EXPECT_EQ(srs1.get_ypos(),srs2.get_ypos());
}

TEST(sorceress, srsMovesUp)
{
	//create 2 srs objects
    sorceress srs1;
    sorceress srs2;
	
	//move one object up by calling the moveU function
    srs1.moveU();
	
	//expect direction to be set to 1 = Up
	EXPECT_EQ(srs1.direction,1);
	
	//check the positions have changed appropriately
    EXPECT_LT(srs1.get_ypos(),srs2.get_ypos());
	EXPECT_EQ(srs1.get_xpos(),srs2.get_xpos());
}


TEST(sorceress, srsMovesDown)
{
	//create 2 srs objects
    sorceress srs1;
    sorceress srs2;
	
	//move one object down by calling the moveD function
    srs1.moveD();
	//expect direction to be set to 2 = Down
	EXPECT_EQ(srs1.direction,2);
	
	//check the positions have changed appropriately
    EXPECT_GT(srs1.get_ypos(),srs2.get_ypos());
	EXPECT_EQ(srs1.get_xpos(),srs2.get_xpos());
}

TEST(sorceress, srsCorrectStartPos)
{
    //create an object of srs
    sorceress srs1;
	
	//check that the initialization positions are correct
    EXPECT_EQ(srs1.get_xpos(), 160);
    EXPECT_EQ(srs1.get_ypos(), 160);

}

TEST(sorceress, MoveFunctionWorksCorrectly)
{
	//create an object of srs
    sorceress srs1;
	
	//check if default no movement results in no movement
	srs1.move(0,0);
    EXPECT_EQ(srs1.rect.getPosition().x, 160);
    EXPECT_EQ(srs1.rect.getPosition().y, 160);
	
	/* different amount of pixel movements, will be checked to whether
	 the correct amount of pixels have been moved based on the
	rectangles position moving correctly */
	srs1.move(10,0);
    EXPECT_EQ(srs1.rect.getPosition().x, 170);
    EXPECT_EQ(srs1.rect.getPosition().y, 160);
	srs1.move(0,10);
    EXPECT_EQ(srs1.rect.getPosition().x, 170);
    EXPECT_EQ(srs1.rect.getPosition().y, 170);
	srs1.move(-20,0);
    EXPECT_EQ(srs1.rect.getPosition().x, 150);
    EXPECT_EQ(srs1.rect.getPosition().y, 170);
	srs1.move(0,-20);
    EXPECT_EQ(srs1.rect.getPosition().x, 150);
    EXPECT_EQ(srs1.rect.getPosition().y, 150);

}


// LIGHTNING CLASS UNIT TESTS 

TEST(lightning, lightningLoads)
{
	//the lightning sprite loads correctly if an exception is not thrown
    EXPECT_NO_THROW(lightning mylightning);
}


TEST(lightning, lightningUpdateFucntionsCorrectlyForDefault)
{	
  lightning test;
  //Test Lightning going Default (Direction =0)
  test.update(0,100,100);
  //check if the co-ords and size of the rectangle of the lightning is correct
  EXPECT_EQ(test.rect.getPosition().x,140);
  EXPECT_EQ(test.rect.getPosition().y,155);
  EXPECT_EQ(test.rect.getSize(),sf::Vector2f(5, 0));
  }

TEST(lightning, lightningUpdateFucntionsCorrectlyForUp)
{
  lightning test;
  //Test Lightning going UP (Direction =1)
  test.update(1,100,100);
  //check if the co-ords and size of the rectangle of the lightning is correct
  EXPECT_EQ(test.rect.getPosition().x,140);
  EXPECT_EQ(test.rect.getPosition().y,115);
  EXPECT_EQ(test.rect.getSize(),sf::Vector2f(5, 0));
}

TEST(lightning, lightningUpdateFucntionsCorrectlyForDown)
{
  lightning test;
  //Test Lightning going Down (Direction =2)
  test.update(2,100,100);
  //check if the co-ords and size of the rectangle of the lightning is correct
  EXPECT_EQ(test.rect.getPosition().x,140);
  EXPECT_EQ(test.rect.getPosition().y,155);
  EXPECT_EQ(test.rect.getSize(),sf::Vector2f(5, 0));
}

TEST(lightning, lightningUpdateFucntionsCorrectlyForRight)
{
  lightning test;
  //Test Lightning going Right (Direction =3)
  test.update(3,100,100);
  //check if the co-ords and size of the rectangle of the lightning is correct
  EXPECT_EQ(test.rect.getPosition().x,150);
  EXPECT_EQ(test.rect.getPosition().y,150);
  EXPECT_EQ(test.rect.getSize(),sf::Vector2f(0, 5));
}

TEST(lightning, lightningUpdateFucntionsCorrectlyForLeft)
{
  lightning test;
  //Test Lightning going Left (Direction =4)
  test.update(4,100,100);
  //check if the co-ords and size of the rectangle of the lightning is correct
  EXPECT_EQ(test.rect.getPosition().x,130);
  EXPECT_EQ(test.rect.getPosition().y,150);
  EXPECT_EQ(test.rect.getSize(),sf::Vector2f(0, 5));
}


//BACKGROUND CLASS UNIT TESTS

TEST(background, backgroundImagesLoadCorrectly)
{
   //Test do all the backgrounds load correctly when
   // the class is called & the specific function is called
	
	background mybackground;
    
	
// No exceptions thrown imply that the backgrounds have all loaded correctly
	EXPECT_NO_THROW(mybackground.back());
	EXPECT_NO_THROW(mybackground.gameOverScreen());
	EXPECT_NO_THROW(mybackground.splash());
	EXPECT_NO_THROW(mybackground.welcome());
	EXPECT_NO_THROW(mybackground.winScreen());
}

//SCORING CLASS UNIT TESTS

TEST(scoring, livesChangesCorrectly)
{
	//create an object of scoring
   scoring score;
   
   //check the start srs lives are correct = 3
   EXPECT_EQ(3,score.srsLives);
   
   //decrement number of srs lives (e.g. if theres a monster collision with srs)
   score.srsLives=score.srsLives-1;
   
   //check lives have decreased correctly
    EXPECT_EQ(2,score.srsLives);
	
	//srs dead state is still at false, as 2 lives remain
	EXPECT_FALSE(score.srsDead);
}

TEST(scoring, textLoadsCorrectly)
{
	//create an object of scoring
   scoring score;
   // No exception is thrown if the font Sansation.tff loads correctly in the function printLives()
   EXPECT_NO_THROW(score.printLives());
}

//GENIE CLASS UNIT TESTS

TEST(genie, genieAutoRightWorks)
{
	//checks if move patrol automatic right works
	
	//create an object of genie
   genie mygenie;
   //sets the position of genies rectangle
   mygenie.rect.setPosition(230, 640);
   //at current positions the patrol function would move genie right by 1 pixel
   mygenie.move_patrol();
   
   //create a second genie object and set its rectangle 1 pixel right
    genie mygenie2;
	mygenie2.rect.setPosition(231, 640);
	
	//if move patrol worked as expected, genie1 matches genie2
    EXPECT_EQ(mygenie.rect.getPosition().x,mygenie2.rect.getPosition().x);
}

TEST(genie, genieAutoLeftWorks)
{
	//create an object of genie
   genie mygenie;
   
   //sets the rectangles position of genie obj
   mygenie.rect.setPosition(230, 640);
   //set the condition of moveright to false (i.e. when genie hits the right wall)
   mygenie.moveright=false;
   
   //by calling move patrol should move genie left by 1 pixel
   mygenie.move_patrol();
   
   //create a 2nd obj of genie and set its rectangle 1 position left
    genie mygenie2;
	mygenie2.rect.setPosition(229, 640);
	
	//if move patrol left worked genie1 should equal genie2
    EXPECT_EQ(mygenie.rect.getPosition().x,mygenie2.rect.getPosition().x);
}

TEST(genie, UpdateMovementWorksAndCorrectSpriteIsSet)
{
	//test whether the genie updateMovement function works as expected
	
   //create an object of genie	
   genie mygenie;
   //call the update movement if sorceress is at 100 (x) and 100 (y)
   mygenie.updateMovement(100,100);
   //the ghost mode for genie is expected to be false
   EXPECT_FALSE(mygenie.ghost);
   //genie is under 500 pixels in proximity/radius to sorceress
   EXPECT_TRUE(mygenie.withinRadius);
   //check the correct not ghost sprite is selected
   EXPECT_EQ(mygenie._genieSprite.getTextureRect(),sf::IntRect(0, 0, 80, 80));
   //call update movement for sorceress at a different position
   mygenie.updateMovement(300,300);
   EXPECT_TRUE(mygenie.withinRadius);
   //set ghost mode to true
   mygenie.ghost=true;
   mygenie.updateMovement(100,100);
   //check correct sprite is set i.e ghost sprite
   EXPECT_EQ(mygenie._genieSprite.getTextureRect(),sf::IntRect(80, 0, 80, 80));
}

//EXPLOSION CLASS UNIT TESTS

TEST(explosion, explosionLoads)
{
    //expect no throw from the constructor as explosion image loads correctly
    EXPECT_NO_THROW(explosion myexplosion);
}

TEST(explosion, correctExplosionSize)
{
	//create an object of explosion called test
	explosion test;
	
	//if the time of impact is 0.5 secs explosion 1 should load
	test.update(0.5,10,10);
	//expect true for explosion 1 loading
	EXPECT_TRUE(test.expPart1);
	
	//if the time of impact is 1 secs explosion 2 should load
	test.update(1,10,10);
	//expect true for explosion 2 loading
	EXPECT_TRUE(test.expPart2);
	
	//if the time of impact is 1.7 secs explosion 3 should load
	test.update(1.7,10,10);
	//expect true for explosion 3 loading
	EXPECT_TRUE(test.expPart3);
	
	//if the time of impact is 3 secs explosion 4 should load
	test.update(3,10,10);
	//expect true for explosion 4 loading
	EXPECT_TRUE(test.expPart4);
}
	

//KILLSRS CLASS UNIT TESTS	

TEST(killSrs, DetectsCollisionAndKillsSorceress)
{
	//create an objects of all 3 classes below
	killSrs test;
	sorceress mysrs;
	scoring myscore;
	
	//create a vector of genies
	std::vector<genie> genieVector;
	//create on object of genies
	genie mygenie;
	//set the rectangles position of genie at the same position as srs
	//thus there will be an expected collison
	mygenie.rect.setPosition(160, 160);
	//push the obj back into the vector
	genieVector.push_back(mygenie);
	
	//set srs lives to 1
	myscore.srsLives=1;
	//pass the variables into kill_srs
	test.kill_srs(mysrs,genieVector,myscore);
	//we expect a collison hence false
	EXPECT_FALSE(myscore.srsDead);
	
	myscore.srsLives=0;// timer condition met and life is reduced
	test.kill_srs(mysrs,genieVector,myscore);
	//srs is dead expected true
	EXPECT_TRUE(myscore.srsDead);
	
}

TEST(killSrs, NoCollisionwithSorceress)
{
	//create an objects of all 3 classes below
	killSrs test;
	sorceress mysrs;
	scoring myscore;
	//create a vector of genies
	std::vector<genie> genieVector;
	//create an obj of genie
	genie mygenie;
	//set the position of the genie rectangle not in the same position as srs
	mygenie.rect.setPosition(460, 960); //No collision possible
	
	//push obj into the vector
	genieVector.push_back(mygenie);
	
	//pass the varaibles in
	test.kill_srs(mysrs,genieVector,myscore);
	//since no collison srs lives remains at 3
	EXPECT_EQ(myscore.srsLives,3);
	//expect srs dead condition to remain false as lives correct
	EXPECT_FALSE(myscore.srsDead);
}

//COLLISION CLASS UNIT TESTS

TEST(collision, noCollisionMonsterAndLightning)
{
	//create a vector of lightning
	std::vector<lightning> lightningVector;
	//create an obj of lightning
	lightning mylightning;
	//set position of lightning rectangle
	mylightning.rect.setPosition(460, 960); //No collision possible
	//push the obj back into the lightning vector
	lightningVector.push_back(mylightning);
	//create an EMPTY Vector of genies (i.e. no genies)
	std::vector<genie> genieVector;
	game mygame;
	//create a collision test obj
	collision test;
	//call the function
	test.mons_lightning(genieVector,lightningVector,mygame.hit_posx,mygame.hit_posy);
	
	//No collision possible cause no genie, so hit_pos for x and y stays at -100
	EXPECT_EQ(mygame.hit_posx,-100);
	EXPECT_EQ(mygame.hit_posy,-100);
	
	//create a genie obj and push into the vector
	genie mygenie;
	mygenie.rect.setPosition(100, 100); //No collision possible
	genieVector.push_back(mygenie);
	
	test.mons_lightning(genieVector,lightningVector,mygame.hit_posx,mygame.hit_posy);
	//hit still not possible (as no intersection) so hit pos wont change
	EXPECT_EQ(mygame.hit_posx,-100);
	EXPECT_EQ(mygame.hit_posy,-100);
	EXPECT_TRUE(mygenie.alive); //genie won't be killed	
}

TEST(collision, CollisionBetweenMonsterAndLightning)
{
	//create a vector of lighting
	std::vector<lightning> lightningVector;
	//create an obj of lightining, set its psition and pass into vector
	lightning mylightning;
	mylightning.rect.setPosition(460, 960);
   //call update to set position and direction of lightning (dir=Up) 
	mylightning.update(1,100,100);
	lightningVector.push_back(mylightning);
	//create a vector of genies
	std::vector<genie> genieVector;
	//create an obj of genie and push back to vector
	genie mygenie;
	mygenie.rect.setPosition(140, 115); 
	genieVector.push_back(mygenie);
	game mygame;
	collision test;
	test.mons_lightning(genieVector,lightningVector,mygame.hit_posx,mygame.hit_posy);
	
	//expect equal since collision will occur
	EXPECT_EQ(mylightning.rect.getPosition().x,mygenie.rect.getPosition().x);
	EXPECT_EQ(mylightning.rect.getPosition().y,mygenie.rect.getPosition().y);
	
}

//TUNNEL CLASS UNIT TESTS

TEST(tunnel, tunnelInitsCorrectly)
{
	//create a vector of tunnels
	std::vector<tunnel> mytunnel;
	//create an obj of tunnels
	tunnel tunnel1;
	tunnel test;
	//pass the tunnel vector and obj into function
	test.start(&mytunnel,tunnel1);
	
	//check does the vector store the correct co-ords read from the txt file
	EXPECT_EQ(80,mytunnel.at(0).rect.getPosition().x);	
	EXPECT_EQ(160,mytunnel.at(0).rect.getPosition().y);	
	EXPECT_EQ(160,mytunnel.at(1).rect.getPosition().x);	
	EXPECT_EQ(160,mytunnel.at(1).rect.getPosition().y);	
	EXPECT_EQ(240,mytunnel.at(2).rect.getPosition().x);	
	EXPECT_EQ(160,mytunnel.at(2).rect.getPosition().y);	
	EXPECT_EQ(240,mytunnel.at(3).rect.getPosition().x);	
	EXPECT_EQ(240,mytunnel.at(3).rect.getPosition().y);	
	EXPECT_EQ(240,mytunnel.at(4).rect.getPosition().x);	
	EXPECT_EQ(320,mytunnel.at(4).rect.getPosition().y);	
	EXPECT_EQ(240,mytunnel.at(5).rect.getPosition().x);	
	EXPECT_EQ(400,mytunnel.at(5).rect.getPosition().y);	
	EXPECT_EQ(240,mytunnel.at(6).rect.getPosition().x);	
	EXPECT_EQ(480,mytunnel.at(6).rect.getPosition().y);	
	EXPECT_EQ(240,mytunnel.at(7).rect.getPosition().x);	
	EXPECT_EQ(560,mytunnel.at(7).rect.getPosition().y);	
	EXPECT_EQ(240,mytunnel.at(8).rect.getPosition().x);	
	EXPECT_EQ(640,mytunnel.at(8).rect.getPosition().y);	
	EXPECT_EQ(80,mytunnel.at(9).rect.getPosition().x);	
	EXPECT_EQ(640,mytunnel.at(9).rect.getPosition().y);	
	EXPECT_EQ(160,mytunnel.at(10).rect.getPosition().x);	
	EXPECT_EQ(640,mytunnel.at(10).rect.getPosition().y);	
	
	}
	
//MONSTERMOVE CLASS UNIT TESTS	
	
TEST(monsterMove, monsterMoveWorksCorrectly)
{
	//create a vector of tunnels
	std::vector<tunnel> mytunnel;
	//create an tunnel obj and push back into the vector
	tunnel tunnel1;
	tunnel1.rect.setPosition(100,100);
	mytunnel.push_back(tunnel1);
	
	//create a vector of genies
	std::vector<genie> genieVector;
    //create a genie obj and push back into the vector
	genie mygenie;
	mygenie.rect.setPosition(200, 100); 
	genieVector.push_back(mygenie);
	
	//create an obj of the monsterMove class
	monsterMove test;
	
	//the monsters position is NOT in a tunnel thus ghosting is true
	test.tunnel_check(mytunnel,genieVector,200,200);
	EXPECT_TRUE(genieVector[0].ghost);
	
	//set new position of tunnel and push into the vector
	tunnel1.rect.setPosition(340,120);
	mytunnel.push_back(tunnel1);
	
	//set genies new position corresponding to the tunnel
	mygenie.rect.setPosition(340, 120); 
	genieVector.push_back(mygenie);
	
	test.tunnel_check(mytunnel,genieVector,400,200);
	//monsters position IS in the tunnel, this ghosting is false (i.e. normal monster)
	EXPECT_FALSE(genieVector[1].ghost);
	
	mygenie.rect.setPosition(340, 120); 
	genieVector.push_back(mygenie);
	
	test.tunnel_check(mytunnel,genieVector,400,200);
	
	//monsters position IS in the tunnel, this ghosting is false (i.e. normal monster)
	EXPECT_FALSE(genieVector[2].ghost);
	
	
	mygenie.rect.setPosition(100, 100); 
	genieVector.push_back(mygenie);
	
	test.tunnel_check(mytunnel,genieVector,400,200);
	//monsters position IS in the tunnel, this ghosting is false (i.e. normal monster)
	EXPECT_FALSE(genieVector[3].ghost);
	
	
	mygenie.rect.setPosition(1000, 1000); 
	genieVector.push_back(mygenie);
	
	test.tunnel_check(mytunnel,genieVector,400,200);
	//monsters position is NOT in a tunnel, this ghosting is true
	EXPECT_TRUE(genieVector[4].ghost);
	
	}
	