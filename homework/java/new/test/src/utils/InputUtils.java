package utils;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class InputUtils {
    private InputStreamReader streamReader;
    private BufferedReader bufferReader;

    private InputStreamReader getInputStreamReader() {
        return new InputStreamReader(System.in);
    }

    private BufferedReader getReader() {
        if(streamReader == null) {
            streamReader = getInputStreamReader();
        }
        bufferReader = new BufferedReader(streamReader);
        return bufferReader;
    }

    public String readLine() {
        String inputText;

        try {
            inputText = getReader().readLine();
        } catch (IOException e) {
            inputText = "";
            e.printStackTrace();
        }
        return inputText;
    }

    public int readInt() {
        try {
            int inputNum = Integer.parseInt(readLine());
            return inputNum;
        } catch(NumberFormatException e) {
            e.printStackTrace();
        }
        return 0;
    }

    public double readDouble() {
        try {
            double inputNum = Double.parseDouble(readLine());
            return inputNum;
        } catch(NumberFormatException e) {
            e.printStackTrace();
        }
        return 0;
    }

    public String[] readArrayLine() {
        return readLine().split(" ");
    }

    public double[] readDoubleArrayLine() {
        String[] stringList = readArrayLine();
        double[] result = new double[stringList.length];
        for(int i = 0; i < stringList.length; i++) {
            result[i] = Double.parseDouble(stringList[i]);
        }
        return result;
    }

    public void close() {
        try {
            bufferReader.close();
            streamReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
