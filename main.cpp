#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define WIFI_SSID "Nikhil's Network"
#define WIFI_PASSWORD "15081947"
#define BOT_TOKEN "Your Bot Tocken"

const int ledPin0 = D0;
const int ledPin3 = D3;
const int ledPin4 = D4;
const int ledPin5 = D5;
const int ledPin6 = D6;
const int ledPin7 = D7;
const int ledPin8 = D8;
const int ledPin9 = D9;
int a,b,c,d,e,f,g,h;
String Pass = "BHARAT";
String trusted="";
const unsigned long BOT_MTBS = 1000; // mean time between scan messages

unsigned long bot_lasttime; // last time messages' scan has been done
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void handleNewMessages(int numNewMessages)
{
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);
  
  String answer;
  for (int i = 0; i < numNewMessages; i++)
  {
    telegramMessage &msg = bot.messages[i];
  
    Serial.println("Received " + msg.text);
    if (msg.chat_id == "***********" || msg.chat_id == trusted){

    if (msg.text == "/start"){
      String keyboardJson = "[[\"Take Control\", \"Status\"]]";
      bot.sendMessageWithReplyKeyboard(msg.chat_id, "Choose from the following options", "", keyboardJson, true);
    }
      
    else if (msg.text == "Status"){
        if(a==0 && b==0 && c== 0 && d== 0 && e==0 && f==0 && g==0 && h==0){
          bot.sendMessage(msg.chat_id, "All of your devices are turned off", "Markdown");
        }
        else{
          bot.sendMessage(msg.chat_id, "List of devices in on mode are ", "Markdown");
          if(a==1){
              bot.sendMessage(msg.chat_id, "Bed room Bulb", "Markdown");
          }

          if(b==1){
              bot.sendMessage(msg.chat_id, "Bed room Fan", "Markdown");
          }

          if(c==1){
              bot.sendMessage(msg.chat_id, "Kitchen Bulb", "Markdown");
          }

          if(d==1){
              bot.sendMessage(msg.chat_id, "Kitchen Fan", "Markdown");
          }

          if(e==1){
              bot.sendMessage(msg.chat_id, "Bath room Bulb", "Markdown");
          }

          if(f==1){
              bot.sendMessage(msg.chat_id, "Hall Bulb", "Markdown");
          }

          if(g==1){
              bot.sendMessage(msg.chat_id, "Hall Fan", "Markdown");
          }

          if(h==1){
              bot.sendMessage(msg.chat_id, "External Power supply", "Markdown");
          }
        }
    }


    else if (msg.text == "Take Control"){
       String keyboardJson = "[[{ \"text\" : \"Bed Room\", \"callback_data\" : \"bedroomnikhil\" }],[{ \"text\" : \"Kitchen\", \"callback_data\" : \"kitchennikhil\" }],[{ \"text\" : \"Bath Room\", \"callback_data\" : \"bathroomnikhil\" }],[{ \"text\" : \"Hall\", \"callback_data\" : \"hallnikhil\" }]]";
        bot.sendMessageWithInlineKeyboard(msg.chat_id, "Tap on the followings to continue", "", keyboardJson);
    }
    else if (msg.text == "bedroomnikhil"){
      bot.sendChatAction(msg.chat_id, "Automating");
      String keyboardJson = "[[{ \"text\" : \"Bulb\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"bbon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"bboff\" }],[{ \"text\" : \"Fan\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"bfon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"bfoff\" }]]";
        bot.sendMessageWithInlineKeyboard(msg.chat_id, "Bed Room:", "", keyboardJson);
    }

    else if (msg.text == "kitchennikhil"){
     bot.sendChatAction(msg.chat_id, "Automating");
     String keyboardJson = "[[{ \"text\" : \"Bulb\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"kbon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"kboff\" }],[{ \"text\" : \"Fan\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"kfon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"kfoff\" }]]";
        bot.sendMessageWithInlineKeyboard(msg.chat_id, "Kitchen:", "", keyboardJson);
    }

    else if (msg.text == "bathroomnikhil"){
      bot.sendChatAction(msg.chat_id, "Automating");
      String keyboardJson = "[[{ \"text\" : \"Bulb\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"baon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"baoff\" }]]";
      bot.sendMessageWithInlineKeyboard(msg.chat_id, "Bath Room:", "", keyboardJson);
    }

    else if (msg.text == "hallnikhil"){
      bot.sendChatAction(msg.chat_id, "Automating");
     String keyboardJson = "[[{ \"text\" : \"Bulb\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"hbon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"hboff\" }],[{ \"text\" : \"Fan\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"hfon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"hfoff\" }],[{ \"text\" : \"External Supply\", \"callback_data\" : \"null\" },{ \"text\" : \"ON\", \"callback_data\" : \"eon\" },{ \"text\" : \"OFF\", \"callback_data\" : \"eoff\" }]]";
        bot.sendMessageWithInlineKeyboard(msg.chat_id, "Hall:", "", keyboardJson);
    }

    else if(msg.text=="bbon"){
      digitalWrite(ledPin0, HIGH);
      a=1;
    }

     else if(msg.text=="bboff"){
      digitalWrite(ledPin0, LOW);
      a=0;
    }

     else if(msg.text=="bfon"){
      digitalWrite(ledPin3, HIGH);
      b=1;
    }

     else if(msg.text=="bfoff"){
      digitalWrite(ledPin3, LOW);
      b=0;
    }

     else if(msg.text=="kbon"){
      digitalWrite(ledPin4, HIGH);
      c=1;
    }

     else if(msg.text=="kboff"){
      digitalWrite(ledPin4, LOW);
      c=0;
    }

    else if(msg.text=="kfon"){
      digitalWrite(ledPin5, HIGH);
      d=1;
    }

    else if(msg.text=="kfoff"){
      digitalWrite(ledPin5, LOW);
      d=0;
    }

    else if(msg.text=="baon"){
      digitalWrite(ledPin6, HIGH);
      e=1;
    }

    else if(msg.text=="baoff"){
      digitalWrite(ledPin6, LOW);
      e=0;
    }
    else if(msg.text=="hbon"){
      digitalWrite(ledPin7, HIGH);
      f=1;
    }

     else if(msg.text=="hboff"){
      digitalWrite(ledPin7, LOW);
      f=0;
    }
    else if(msg.text=="hfon"){
      digitalWrite(ledPin8, HIGH);
      g=1;
    }

     else if(msg.text=="hfoff"){
      digitalWrite(ledPin8, LOW);
      g=0;
    }
    else if(msg.text=="eon"){
      digitalWrite(ledPin9, HIGH);
      h=1;
    }

     else if(msg.text=="eoff"){
      digitalWrite(ledPin9, LOW);
      h=0;
    }

    else if(msg.text=="null"){
    bot.sendMessage(msg.chat_id, "Tap on 'ON' and 'OFF' only");
    }

    else{
      bot.sendMessage(msg.chat_id, "Sorry! Invalid Command!");

    }
  }
  else if(msg.text==Pass){
    trusted = msg.chat_id;
    bot.sendMessage(msg.chat_id, "Correct Password! Now you Have access");
    bot.sendMessage("***********", "Alert!!! Some One used your password to login.....");
  }
  else{
    bot.sendMessage(msg.chat_id, "Sorry to say that...But I am unable to recognize you.");
    bot.sendMessage(msg.chat_id, "Could you provide me your password..?");
    bot.sendMessage("***********", "Alert\n Chat ID: ", "Markdown");
    bot.sendMessage("***********", msg.chat_id, "Markdown");
    bot.sendMessage("***********", msg.from_name, "Markdown");
    String strValue = String(msg.longitude);
    String strValue1 = String(msg.latitude);
    bot.sendMessage("***********", strValue, "Markdown");
    bot.sendMessage("***********", strValue1, "Markdown");

    bot.sendMessage("***********", "Is trying to get access with wrong password", "Markdown");
  }
  }
}

void bot_setup()
{
  const String commands = F("["
                            "{\"command\":\"help\",  \"description\":\"Get bot usage help\"},"
                            "{\"command\":\"start\", \"description\":\"Message sent when you open a chat with a bot\"},"
                            "{\"command\":\"status\",\"description\":\"Answer device current status\"}" // no comma on last command
                            "]");
  bot.setMyCommands(commands);
  //bot.sendMessage("25235518", "Hola amigo!", "Markdown");
}

void setup()
{
  Serial.begin(9600);
  Serial.println();
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);

  // attempt to connect to Wifi network:
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  // Check NTP/Time, usually it is instantaneous and you can delete the code below.
  Serial.print("Retrieving time: ");
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

  bot_setup();
}

void loop()
{
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}
