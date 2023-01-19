package v1.data.interfaces;

import java.sql.ResultSet;

public interface IDatabase {
    public void initialize();

    public void open(String name);

    public void close();

    public int executeUpdate(String sql);
    
    public ResultSet executeQuery(String sql);
}
