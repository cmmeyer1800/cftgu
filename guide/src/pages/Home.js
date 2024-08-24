import { FaBook } from "react-icons/fa";
import { useState } from "react";
import Fuse from 'fuse.js';

import './home.css'
import { Column, Columns } from '../components/Bulma'


const articles = [
    {title: "The Basics", subtitle: "Where else to start from but physics?",
     img: "/transistor.webp", link: "/articles/the-basics"}
]


const ContentPreview = (props) => {
    return (
        <div className='cell is-col-span 1'>
            <div className='box'>
                <div className='has-text-centered'>
                    <h3 className='subtitle mb-0'>{props.title}</h3>
                    <h5>{props.subtitle}</h5>
                </div>
                <div className='mt-2'>
                    <figure className="image" style={{width: "100%", background: "white", borderRadius: "2%"}}>
                        <img src={props.img} />
                    </figure>
                </div>
                <div className='has-text-centered mt-2'>
                    <a href={props.link}><span className="icon-text has-text-text">
                        <span>Read</span>
                        <span className="icon">
                            <FaBook/>
                        </span>
                    </span></a>
                </div>
            </div>
        </div>
    )
}


export default function Home(){
    const [results, setResults] = useState(articles)
    const [search, setSearch] = useState('')

    const handleSearch = (text) => {
        if(text === ""){
            setResults(articles);
        } else {
            const fuse = new Fuse(articles, {keys: ['title', 'subtitle']});
            setResults(fuse.search(text).map((res) => res.item));
        }
        setSearch(text);
    }

    return (
        <>
            <div className="has-text-centered">
                <h1 className="title is-1 _main-title">Computing From The Ground Up</h1>
            </div>
            <Columns className="mt-4">
                <Column className="is-8 is-offset-2">
                    <input className='input is-medium' type='input' placeholder="Search For Article"
                           value={search} onChange={(e) => handleSearch(e.target.value)}></input>
                    <div className='fixed-grid has-3-cols mt-4'>
                        <div className='grid'>
                            { results.map((val, idx) =>
                                <ContentPreview key={idx} {...val} />
                            )}
                        </div>
                    </div>
                </Column>
            </Columns>
        </>
    )
}