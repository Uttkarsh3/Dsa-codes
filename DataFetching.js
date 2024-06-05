import axios from 'axios';
import React,{useState,useEffect} from 'react';

const DataFetching =()=>{
    const[data,setData]=useState(null);
    const[loading,setLoading]=useState(true);
    const[error,setError]=useState(null);

    const FetchData=async()=>{
        try{
            const a = await axios.get('https://jsonplaceholder.typicode.com/posts');
            setData(a.data);
            setLoading(false);
        }catch(error){
            setError(error);
            setLoading(false);
        }
    };

    useEffect(()=>{
        FetchData();
    },[]);

    if(loading)
        return <div>Loading...</div>;

    if(error)
        return <div>Error:{error.message}</div>;

    return(
        <div>
            <h2>Fetched Data</h2>
           <pre>{JSON.stringify(data,null,2)}</pre>
        </div>
    );
};

export default DataFetching;