package v1.data.services.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

import v1.data.interfaces.IDatabase;

public class DbService implements IDatabase {
    static final int ERROR_CODE = -1;
    static String dbName = "finance.db";

    private final String driverName = "org.sqlite.JDBC";
    private final String connectionName = "jdbc:sqlite:";
    private Connection connection = null;
    private Statement statement = null;

    @Override
    public void initialize() {
        open(dbName);
        System.out.println("Db connected");
    }

    @Override
    public void open(String name) {
        if (connection != null) {
            return;
        }
        try {
            Class.forName(driverName);
            connection = DriverManager.getConnection(connectionName + name);
            statement = connection.createStatement();

        } catch (Exception e) {
            e.printStackTrace();
            return;
        }
    }

    @Override
    public int executeUpdate(String sql) {
        if (statement == null) {
            return ERROR_CODE;
        }
        try {
            return statement.executeUpdate(sql);
        } catch (SQLException e) {
            e.printStackTrace();
            return ERROR_CODE;
        }

    }

    @Override
    public boolean executeQuery(String sql) {
        if (statement == null) {
            return false;
        }
        try {
            return statement.execute(sql);
        } catch (SQLException e) {
            return false;
        }

    }

    @Override
    public void close() {
        try {
            if (connection != null)
                connection.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }

    }
}
