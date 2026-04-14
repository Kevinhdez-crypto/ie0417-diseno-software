Kevin Hernandez Umana. C33773
Tarea 02

Caso seleccionado: Plataforma de pedidos para un restaurante.

## a. Lista de requerimientos
 
### Requerimientos funcionales
 
1. El sistema debe permitir al usuario registrarse con correo electrónico y contraseña.  
2. El sistema debe permitir al usuario iniciar sesión.  
3. El sistema debe mostrar el menú del restaurante con los productos disponibles.  
4. El sistema debe permitir agregar productos al carrito de compras.  
5. El sistema debe permitir realizar pedidos y confirmar la compra.  
6. El sistema debe permitir al usuario consultar el historial de pedidos.  
 
---
 
### Requerimientos no funcionales
 
1. El sistema debe ser accesible desde dispositivos móviles y computadoras (responsive).  
2. El sistema debe responder a las acciones del usuario en menos de 2 segundos.  
3. El sistema debe garantizar la seguridad de los datos mediante autenticación y cifrado.  
 
---
 
### Requerimiento técnico / de interfaz
 
1. La interfaz debe ser intuitiva y permitir la navegación entre menú, carrito y pedidos mediante un menú principal visible.
 
---
 
## b. Casos de uso
 
---
 
### Caso de uso 1: Realizar pedido
 
**Actor:** Usuario  
 
**Precondiciones:**  
- El usuario debe haber iniciado sesión.  
- El menú debe estar disponible.  
 
**Postcondiciones:**  
- El pedido queda registrado en el sistema.  
- El carrito queda vacío.  
 
**Flujo principal:**  
1. El usuario accede al menú.  
2. Selecciona productos.  
3. Agrega productos al carrito.  
4. Confirma el pedido.  
5. El sistema registra el pedido.  
 
**Flujos alternativos:**  
- 4a. Si el carrito está vacío → el sistema muestra un mensaje de error.  
- 2a. Si un producto no está disponible → el sistema lo indica y no permite seleccionarlo.  
 
---
 
### Caso de uso 2: Registro de usuario
 
**Actor:** Usuario  
 
**Precondiciones:**  
- El usuario no debe estar registrado previamente.  
 
**Postcondiciones:**  
- El usuario queda registrado en el sistema.  
 
**Flujo principal:**  
1. El usuario accede a la opción de registro.  
2. Ingresa correo y contraseña.  
3. El sistema valida los datos.  
4. El sistema crea la cuenta.  
 
**Flujos alternativos:**  
- 3a. Si el correo ya existe → el sistema muestra un mensaje de error.  
- 3b. Si la contraseña no cumple requisitos → el sistema solicita corrección.  
 
---
 
## c. Diagrama UML de casos de uso

<img width="921" height="555" alt="image" src="https://github.com/user-attachments/assets/52291713-197a-4e65-826b-a9e65ef54dcb" />
