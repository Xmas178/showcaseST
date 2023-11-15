import pytesseract
from PIL import Image

# Lataa kuva
image = Image.open('kuva5.png')

# Käytä Tesseract OCR kuvan tekstiin lukemiseen
text = pytesseract.image_to_string(image, config='--psm 6 --oem 3')

# Avaa tiedosto tulosten tallentamista varten
with open('tulokset.txt', 'w', encoding='utf-8') as file:

    # Etsi sanoja ja arvoja
    keywords = ['summa', 'amount', 'yhteensä', 'yht', '14.00%', '24.00%']

    for keyword in keywords:
        index = text.lower().find(keyword)
        if index != -1:
            # Etsi rivin alusta sanojen loppuun
            line_start = text.rfind('\n', 0, index) + 1
            line_end = text.find('\n', index)

            # Tulosta ja tallenna löydetty teksti
            found_text = text[line_start:line_end].strip()

            print(f"{keyword}: {found_text}€")
            file.write(f"{found_text}€\n")
