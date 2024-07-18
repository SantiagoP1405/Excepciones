# Excepciones
Práctica de las excepciones en C++

Santiago Patricio Gómez Ochoa | A01735171
Programación Orientada a Objetos
11/06/2024

INSTRUCCIONES DE USO DEL ARCHIVO mainExcepciones

Instrucción para compilar el programa
> g++ mainExcepciones.cpp    

Instrucción para ejecutar el programa
> ./a.out

La función validateGameParameters se encarga de validar
los parámetros de configuración del juego.Recibe varios 
parámetros como el tamaño del tablero, número de jugadores,
serpientes, escaleras, recompensas y penalizaciones.
Revisa cada parámetro y si encuentra valores 
inválidos (por ejemplo, un tamaño de tablero no positivo,
un número de jugadores menor o igual a uno, etc.), 
agrega un mensaje de error a un vector de errores (errors).
Si se encuentra al menos un error, se lanza una excepción 
de tipo std::runtime_error con un mensaje que contiene 
todos los errores encontrados.

El bloque Try intenta ejecutar el código que podría lanzar
una excepción. Se solicitan los parámetros del juego al usuario,
se llama a la función validateGameParameters para verificar 
los parámetros, y si alguno de los parámetros es inválido,
se lanza una excepción y se interrumpe la ejecución normal
del programa.

Asimismo, si se lanza una excepción de tipo std::runtime_error,
el flujo de ejecución se transfiere al bloque catch. Dentro del
bloque catch, se captura la excepción y se imprime el mensaje de
error usando std::cerr. Después de manejar la excepción, el
programa retorna un código de error (1) y termina.
