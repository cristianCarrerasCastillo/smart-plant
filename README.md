# Smart-plant

Proyecto de Riego Automático con Arduino Nano

Este repositorio contiene el código fuente y la documentación para un proyecto de riego automático utilizando un Arduino Nano, un sensor de humedad de suelo, una bomba sumergible de 3.3V, una resistencia de 2.2k ohmios y un transistor TIP120. Este sistema está diseñado para mantener el nivel de humedad del suelo dentro de un rango específico, activando la bomba de agua cuando sea necesario.

## Contenido del Repositorio

- **/src**: Este directorio contiene el código fuente del programa. El archivo principal es `main.cpp`.

## Requisitos del Hardware

1. **Arduino Nano**: La unidad principal que controla el sistema. (https://es.aliexpress.com/item/1005005967644175.html)
2. **Sensor de Humedad de Suelo**: Para medir el nivel de humedad en el suelo.(https://es.aliexpress.com/item/1005005850226701.html)
3. **Bomba Sumergible de 3.3V**: La bomba de agua que se activará para el riego.(https://es.aliexpress.com/item/32676646343.html)
4. **Resistencia de 2.2k ohmios**: Utilizada en la configuración del transistor.
5. **Transistor TIP120**: Para controlar la activación de la bomba.

## Uso

1. **Calibración del Sensor de Humedad**: Antes de usar el sistema, calibra el sensor de humedad según sus propios requerimientos.

2. **Alimentación del Sistema**: Conecta el Arduino Nano a una fuente de alimentación adecuada y asegúrate de que todos los componentes estén correctamente conectados.

3. **Observación del Riego Automático**: Una vez que el sistema esté encendido, observa cómo la bomba se activa automáticamente cuando el suelo alcanza un nivel de humedad por debajo del umbral establecido.

## Contribuciones

Las contribuciones son bienvenidas. Si encuentras problemas, tienes sugerencias o deseas mejorar la documentación, no dudes en abrir un problema o enviar una solicitud de extracción.

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo [LICENSE](LICENSE) para obtener más detalles.