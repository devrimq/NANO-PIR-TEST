
# PIR Hareket Dedektörü

Arduino ile HC-SR501 PIR sensörü kullanarak hareket algılama ve LED kontrolü.

## 📦 Gereken Malzemeler

- Arduino (Uno, Nano, Mega vb.)
- HC-SR501 PIR Sensörü
- 5mm LED
- 220Ω Direnç
- Jumper kabloları
- Breadboard (isteğe bağlı)

## 🔌 Bağlantı Şeması

| PIR Sensörü | Arduino | LED |
|-------------|---------|-----|
| VCC         | 5V      | -   |
| GND         | GND     | -   |
| OUT         | D2      | -   |
| -           | D3      | Anot (+) -> 220Ω -> D3 |
| -           | GND     | Katot (-) |

### LED Bağlantısı
