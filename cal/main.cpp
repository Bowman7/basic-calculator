#include<SFML/Graphics.hpp>
#include<iostream>
#include<map>
#include<iterator>
#include<memory>
#include<stdio.h>
namespace Textures
{
	enum ID
	{
		cal,one
	};
}
class TextureHolder
{
private:
	std::map<Textures::ID,
		 std::unique_ptr<sf::Texture>> mTextureMap;
public:
	void load(Textures::ID id,const std::string& filename);
	sf::Texture& get(Textures::ID id);
	const sf::Texture& get(Textures::ID id) const;
};
void TextureHolder::load(Textures::ID id,const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	texture->loadFromFile(filename);

	mTextureMap.insert(std::make_pair(id,std::move(texture)));
	
}
sf::Texture& TextureHolder::get(Textures::ID id)
{
	auto found=mTextureMap.find(id);
	return *found->second;
}
	
class mainCls
{
public:
	mainCls();
	void run();
private:
	void update();
	void render();
	void render2();
	void processEvents();
	void handleInput();
	bool one=false;
	float mouseX,mouseY;
private:
	sf::RenderWindow mWindow;
	sf::Texture texture;
	sf::Sprite mSprite;
	sf::Sprite pland;
	TextureHolder textures;
      
	
};
mainCls::mainCls()
	:mWindow(sf::VideoMode(400,600),"curel scrren"),mSprite(),texture()
{
	//TextureHolder textures;
	textures.load(Textures::cal,"/home/batu/plus/basic-calculator/cal/calc2.png");
	textures.load(Textures::one,"/home/batu/plus/basic-calculator/cal/nums.png");
	//sf::Sprite pland;
	pland.setTexture(textures.get(Textures::cal));
	mSprite.setTexture(textures.get(Textures::one));
	pland.setPosition(0.f,0.f);
//	mSprite.setPosition(100.f,200.f);
}
void mainCls::run()
{
	sf::Clock clock;
	sf::Time timeSince=sf::Time::Zero;
	while(mWindow.isOpen())
	{
		processEvents();
		timeSince+=clock.restart();
		while(timeSince>sf::seconds(1.f/60.f))
		{
			timeSince-=sf::seconds(1.f/60.f);
			processEvents();
			update();
		}
		render();
	}
	
}void mainCls::processEvents()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::MouseMoved:
			mouseX=sf::Mouse::getPosition(mWindow).x;
			mouseY=sf::Mouse::getPosition(mWindow).y;
			handleInput();
		}
		
	}
}
void mainCls::handleInput()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if(mouseX<100 && mouseY<100)
		{
			one =true;
		}
	}
}
void mainCls::update()
{
	if(one)
	{
		sf::IntRect num1(0.f,0.f,50.f,75.f);
		mSprite.setTextureRect(num1);
		mSprite.setPosition(0.f,0.f);
	}
	
}
void mainCls::render()
{
	sf::Vector2i posi=sf::Mouse::getPosition();
	//printf("posx : %d posy: %d",posi.x,posi.y);
	mWindow.clear();
	mWindow.draw(pland);
	render2();
	mWindow.display();
}
void mainCls::render2()
{
	if(one)
	{
		mWindow.draw(mSprite);
	}
}
int main()
{
	mainCls cl;
	cl.run();
}
	
