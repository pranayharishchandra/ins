import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class DESExample {

    public static void main(String[] args) {
        try {
            // Key generation
            KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
            SecretKey secretKey = keyGenerator.generateKey();

            // Encryption
            Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
            cipher.init(Cipher.ENCRYPT_MODE, secretKey);
            String plaintext = "Hello, World!";
            byte[] encryptedBytes = cipher.doFinal(plaintext.getBytes());
            String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
            System.out.println("Encrypted Text: " + encryptedText);

            // Decryption
            cipher.init(Cipher.DECRYPT_MODE, secretKey);
            byte[] decryptedBytes = cipher.doFinal(Base64.getDecoder().decode(encryptedText));
            String decryptedText = new String(decryptedBytes);
            System.out.println("Decrypted Text: " + decryptedText);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
/*===========
secrete key: www.reva.edu
encrypted value: /Xaskrjfgnasfd234asfaser34r23ewqdfrc
decrypted value:  www.reva.edu
==============*/
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

class Main {

    Cipher ecipher;
    Cipher dcipher;

    Main(SecretKey key) throws Exception {
        ecipher = Cipher.getInstance("DES");
        dcipher = Cipher.getInstance("DES");
        ecipher.init(Cipher.ENCRYPT_MODE, key);
        dcipher.init(Cipher.DECRYPT_MODE, key);
    }

    public String encrypt(String str) throws Exception {
        // Encode the string into bytes using utf-8
        byte[] utf8 = str.getBytes("UTF8");

       
 // Encrypt
        byte[] enc = ecipher.doFinal(utf8);

        // Encode bytes to base64 to get a string

        return Base64.getEncoder().encodeToString(enc);

    }

    public String decrypt(String str) throws Exception {
        // Decode base64 to get bytes
        byte[] dec = Base64.getDecoder().decode(str);

        byte[] utf8 = dcipher.doFinal(dec);

        // Decode using utf-8
        return new String(utf8, "UTF8");
    }

    public static void main(String[] argv) throws Exception {
        final String secretText = "www.reva.edu.in";
        System.out.println("SecretText: " + secretText);
        SecretKey key = KeyGenerator.getInstance("DES").generateKey();
        Main encrypter = new Main(key);
        String encrypted = encrypter.encrypt(secretText);
        System.out.println("Encrypted Value: " + encrypted);
        String decrypted = encrypter.decrypt(encrypted);
        System.out.println("Decrypted: " + decrypted);

    }
}

