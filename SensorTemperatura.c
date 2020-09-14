#include <Wire.h> /* Biblioteca para I2C (O protocolo serial síncrono I2C, também conhecido como TWI, utiliza de dois fios (SDA: Dados; SCL: Clock) para                                                                 realizar uma comunicação half duplex, ou seja, é possível trasmitir e receber informações, mas não ao mesmo tempo,                                                                 apenas um sentido por vez. Forma-se um barramento endereçável onde cada componente na rede possui um endereço                                                                 para ser identificado para que a informação possa ser designda para o destinatário correto). */
#include <SparkFunMLX90614.h> // Biblioteca para comunicação com o sensor infravermelho.

IRtherm therm; // Cria um objeto para o sensor de temperatura.

// -- Configurações iniciais --
void setup ( ) {

	Serial.begin (9600);
	therm.begin ( );
	therm.setUnit (TEMP_C); // Pode ser TEMP_F para Fahrenheit ou TEMP_K para Kelvin.	
}

// -- Loop infinito --
void loop ( ) {

	if (therm.read ( ) ) {

		Seria.print ("Objeto: "+String (therm.object ( ), 2) );
		Serial.write (' ° ');
		Serial.println (" C ");

		Serial.print ("Ambiente: "+String (therm.ambient ( ), 2) );
		Serial.write (' ° ');
		Serial.println (" C ");
		
		Serial.println ( );
	}

	delay (1500); // Atualização a cada 1,5 segundo.
}