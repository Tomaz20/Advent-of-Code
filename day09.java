import java.util.*;
import java.io.*;

class Day9 { 
    static ArrayList<City> cities = new ArrayList<>();
    static Map<String,Integer> routes = new HashMap<>();

    public static void main(String[] args) throws IOException{
        Scanner scan = new Scanner(new File("input.txt"));
        while(scan.hasNext()) {
            String[] lineSplit = scan.nextLine().split(" ");
            City c = getCity(lineSplit[0]);
            c.addDist(getCity(lineSplit[2]),Integer.parseInt(lineSplit[4]));
        }

        for(City c : cities) {
            getRoutes(c,new ArrayList<>(),0);
        }

        Integer[] ar = routes.values().toArray(new Integer[0]);
        Arrays.sort(ar);
        System.out.println("Shortest: " + ar[0] + "\nLongest: " + ar[ar.length-1]); //ar[0] part1,ar[ar.length-1] part2
    }

    public static City getCity(String s) {
        for(City c : cities)
            if(c.name.equals(s))
                return c;
        City city = new City(s);
        cities.add(city);
        return city;
    }

    public static void getRoutes(City city,ArrayList<String> list,int sum) {
        list.add(city.name);
        for(City c : city.dist.keySet()) {
            if(!list.contains(c.name))
                getRoutes(c,new ArrayList<String>(list),sum+city.dist.get(c));
            else if(list.size() == cities.size())
                routes.put(Arrays.toString(list.toArray()),sum);
        }
    }
}

class City {
    String name;
    Map<City,Integer> dist = new HashMap<City,Integer>();

    City(String n) {
        name = n;
    }
    public void addDist(City c,int d) {
        dist.put(c,d);
        c.dist.put(this,d);
    }
}
